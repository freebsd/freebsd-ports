--- ui/zenoui/comctrl/gv/zgraphicstextitem.cpp.orig	2024-09-30 13:46:54 UTC
+++ ui/zenoui/comctrl/gv/zgraphicstextitem.cpp
@@ -568,7 +568,7 @@ void ZEditableTextItem::keyPressEvent(QK
                 // it's very difficult to get current viewport, so we get it by current cursor.
                 // but when we move the cursor out of the view, we can't get the current view.
 
-                static QRect screen = QApplication::desktop()->screenGeometry();
+                static QRect screen = QGuiApplication::primaryScreen()->geometry();
                 static const int _yOffset = ZenoStyle::dpiScaled(20);
                 QPointF cursorPos = this->cursor().pos();
                 QPoint viewPoint = view->mapFromGlobal(this->cursor().pos());
@@ -614,9 +614,8 @@ bool ZEditableTextItem::event(QEvent * e
             QString filter = property("filter").toString();
             if (!filter.isEmpty())
             {
-                QRegExp rx(filter);
-                rx.setPatternSyntax(QRegExp::Wildcard);
-                m_validator = new QRegExpValidator(rx, this);
+                QRegularExpression rx(QRegularExpression::wildcardToRegularExpression(filter));
+                m_validator = new QRegularExpressionValidator(rx, this);
             }
         }
     }
