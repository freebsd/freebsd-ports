--- kipi-plugins/rawconverter/batchdialog.cpp.orig	2008-09-16 12:29:47.000000000 +0200
+++ kipi-plugins/rawconverter/batchdialog.cpp	2008-09-16 12:32:59.000000000 +0200
@@ -111,7 +111,7 @@
 
     m_decodingSettingsBox = new KDcrawIface::DcrawSettingsWidget(m_page, false, true, true);
     m_saveSettingsBox     = new SaveSettingsWidget(m_page);
-    m_decodingSettingsBox->insertTab(m_saveSettingsBox, i18n("Save settings"));
+    m_decodingSettingsBox->addItem(m_saveSettingsBox, i18n("Save settings"));
 
     m_progressBar = new KProgress(m_page);
     m_progressBar->setMaximumHeight( fontMetrics().height()+2 );
