--- kipi-plugins/rawconverter/singledialog.cpp.orig	2008-09-16 12:30:04.000000000 +0200
+++ kipi-plugins/rawconverter/singledialog.cpp	2008-09-16 12:35:16.000000000 +0200
@@ -96,7 +96,7 @@
 
     m_decodingSettingsBox = new KDcrawIface::DcrawSettingsWidget(page, false, true, true);
     m_saveSettingsBox     = new SaveSettingsWidget(m_decodingSettingsBox);
-    m_decodingSettingsBox->insertTab(m_saveSettingsBox, i18n("Save settings"));
+    m_decodingSettingsBox->addItem(m_saveSettingsBox, i18n("Save settings"));
 
     mainLayout->addMultiCellWidget(m_previewWidget, 0, 1, 0, 0);
     mainLayout->addMultiCellWidget(m_decodingSettingsBox, 0, 0, 1, 1);
