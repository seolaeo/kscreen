/*
 * Copyright 2013  Daniel Vrátil <dvratil@redhat.com>
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License as
 * published by the Free Software Foundation; either version 2 of
 * the License or (at your option) version 3 or any later version
 * accepted by the membership of KDE e.V. (or its successor approved
 * by the membership of KDE e.V.), which shall act as a proxy
 * defined in Section 14 of version 3 of the license.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 *
 */

#ifndef UNIFIEDOUTPUTCONFIG_H
#define UNIFIEDOUTPUTCONFIG_H

#include "outputconfig.h"

namespace KScreen
{
class Output;
class Config;
}

class UnifiedOutputConfig : public OutputConfig
{
    Q_OBJECT
  public:
    explicit UnifiedOutputConfig(KScreen::Config *config, QWidget *parent);
    virtual ~UnifiedOutputConfig();

    void setOutput(KScreen::Output *output);

  private Q_SLOTS:
    void slotResolutionChanged(const QSize &size);

  private:
    virtual void initUi();
    KScreen::Output* createFakeOutput();
    QString findBestMode(const KScreen::Output *output, const QSize &size);

  private:
    KScreen::Config *mConfig;
    QList<KScreen::Output*> mClones;
};

#endif // UNIFIEDOUTPUTCONFIG_H