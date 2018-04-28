Populate the mail-client drop down on FreeBSD too. Otherwise only the 'default' entry can 
be selected (which launches the one defined via system settings).

--- extra/kipi-plugins/sendimages/settingswidget.cpp.orig	2017-08-04 15:23:02 UTC
+++ extra/kipi-plugins/sendimages/settingswidget.cpp
@@ -92,7 +92,7 @@ SettingsWidget::SettingsWidget(QWidget* const parent)
 
     d->mailAgentName = new QComboBox(this);
     d->mailAgentName->insertItem(EmailSettings::DEFAULT,       i18nc("default desktop mail agent", "Default"));
-#ifdef Q_OS_LINUX
+#if defined(Q_OS_LINUX) || defined(Q_OS_FREEBSD)
     d->mailAgentName->insertItem(EmailSettings::BALSA,         QLatin1String("Balsa"));
     d->mailAgentName->insertItem(EmailSettings::CLAWSMAIL,     QLatin1String("Claws Mail"));
     d->mailAgentName->insertItem(EmailSettings::EVOLUTION,     QLatin1String("Evolution"));
