--- ui/zenoui/comctrl/dialog/zframelessdialog.cpp.orig	2024-09-30 13:46:54 UTC
+++ ui/zenoui/comctrl/dialog/zframelessdialog.cpp
@@ -63,7 +63,7 @@ void ZFramelessDialog::initTitleWidget()
 
     QVBoxLayout* pLayout = new QVBoxLayout(this);
     pLayout->addWidget(pTitleWidget);
-    pLayout->setMargin(0);
+    pLayout->setContentsMargins(0, 0, 0, 0);
 }
 
 void ZFramelessDialog::mousePressEvent(QMouseEvent* event)
