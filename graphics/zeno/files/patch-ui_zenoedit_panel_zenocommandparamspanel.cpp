--- ui/zenoedit/panel/zenocommandparamspanel.cpp.orig	2024-09-30 13:46:54 UTC
+++ ui/zenoedit/panel/zenocommandparamspanel.cpp
@@ -59,7 +59,7 @@ void ZenoCommandParamsPanel::initUi()
     pHLayout->addWidget(m_pExportButton);
     pLayout->addLayout(pHLayout);
     pLayout->addWidget(m_pTableWidget);
-    pLayout->setMargin(0);
+    pLayout->setContentsMargins(0, 0, 0, 0);
 }
 
 void ZenoCommandParamsPanel::initConnection()
