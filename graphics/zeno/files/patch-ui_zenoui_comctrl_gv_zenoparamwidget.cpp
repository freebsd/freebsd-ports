--- ui/zenoui/comctrl/gv/zenoparamwidget.cpp.orig	2024-09-30 13:46:54 UTC
+++ ui/zenoui/comctrl/gv/zenoparamwidget.cpp
@@ -190,7 +190,7 @@ void ZenoParamLineEdit::keyPressEvent(QK
                 // it's very difficult to get current viewport, so we get it by current cursor.
                 // but when we move the cursor out of the view, we can't get the current view.
 
-                static QRect screen = QApplication::desktop()->screenGeometry();
+                static QRect screen = QGuiApplication::primaryScreen()->geometry();
                 static const int _yOffset = ZenoStyle::dpiScaled(20);
                 QPointF cursorPos = this->cursor().pos();
                 QPoint viewPoint = view->mapFromGlobal(this->cursor().pos());
@@ -744,7 +744,7 @@ ZenoParamOpenPath::ZenoParamOpenPath(con
     plineEdit->setReadOnly(true);
     pLayout->addWidget(plineEdit);
     pLayout->addWidget(openBtn);
-    pLayout->setMargin(0);
+    pLayout->setContentsMargins(0, 0, 0, 0);
     pWidget->setLayout(pLayout);
     pWidget->setAutoFillBackground(true);
     setWidget(pWidget);
@@ -1063,7 +1063,7 @@ void ZenoParamGroupLine::paint(QPainter
     //draw text
     QFont font = QApplication::font();
     QFontMetrics fm(font);
-    qreal width = fm.width(m_text);
+    qreal width = fm.horizontalAdvance(m_text);
     QPen pen;
     pen.setColor(QColor(94, 103, 115));
     painter->setPen(pen);
