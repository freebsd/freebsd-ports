--- ui/zenoedit/dock/docktabcontent.cpp.orig	2024-09-30 13:46:54 UTC
+++ ui/zenoedit/dock/docktabcontent.cpp
@@ -116,7 +116,7 @@ ZTextIconButton::ZTextIconButton(const Q
     m_pButton->setSizePolicy(QSizePolicy(QSizePolicy::Minimum, QSizePolicy::Expanding));
     m_pLablel->setSizePolicy(QSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding));
     QHBoxLayout* pLayout = new QHBoxLayout(this);
-    pLayout->setMargin(0);
+    pLayout->setContentsMargins(0, 0, 0, 0);
     pLayout->addWidget(m_pLablel);
     pLayout->addWidget(m_pButton);
     connect(m_pButton, &QPushButton::clicked, this, &ZTextIconButton::clicked);
@@ -366,10 +366,8 @@ void DockContent_Editor::initToolbar(QHB
 
     Callback_EditFinished funcZoomEdited = [=](QVariant newValue) {
         const QString& percent = newValue.toString();
-        QRegExp rx("(\\d+)\\%");
-        rx.indexIn(percent);
-        auto caps = rx.capturedTexts();
-        qreal scale = caps[1].toFloat() / 100.;
+        static const QRegularExpression rx("(\\d+)\\%");
+        qreal scale = rx.match(percent).captured(1).toFloat() / 100.;
         QAction act("zoom");
         act.setProperty("ActionType", ZenoMainWindow::ACTION_ZOOM);
         if (m_pEditor)
