--- ui/zenoedit/dock/zenodocktitlewidget.cpp.orig	2024-09-30 13:46:54 UTC
+++ ui/zenoedit/dock/zenodocktitlewidget.cpp
@@ -52,7 +52,7 @@ void ZenoDockTitleWidget::setupUi()
 
 	pHLayout->addWidget(pDockOptionsBtn);
 	pHLayout->setContentsMargins(0, 0, 0, 0);
-	pHLayout->setMargin(0);
+	pHLayout->setContentsMargins(0, 0, 0, 0);
 
 	pLayout->addLayout(pHLayout);
 
