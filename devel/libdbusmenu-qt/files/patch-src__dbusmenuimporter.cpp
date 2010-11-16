--- ./src/dbusmenuimporter.cpp.orig	2010-09-23 10:08:35.000000000 +0000
+++ ./src/dbusmenuimporter.cpp	2010-11-12 14:49:39.000000000 +0000
@@ -32,6 +32,8 @@
 #include <QSignalMapper>
 #include <QTime>
 #include <QTimer>
+#include <QToolButton>
+#include <QWidgetAction>
 
 // Local
 #include "dbusmenuitem_p.h"
@@ -41,7 +43,6 @@
 
 //#define BENCHMARK
 #ifdef BENCHMARK
-#include <QTime>
 static QTime sChrono;
 #endif
 
@@ -66,6 +67,29 @@
     DBusMenuImporterMethod m_method;
 };
 
+class EventSniffer : public QObject
+{
+public:
+    EventSniffer(QObject *parent = 0)
+        : QObject(parent) { }
+
+    ~EventSniffer() { }
+
+    bool eventFilter(QObject *object, QEvent *event)
+    {
+        Q_UNUSED(object);
+
+        if (event->type() == QEvent::Paint ||
+            event->type() == QEvent::KeyPress ||
+            event->type() == QEvent::KeyRelease) {
+            return false;
+        }
+
+        event->accept();
+        return true;
+    }
+};
+
 class DBusMenuImporterPrivate
 {
 public:
@@ -143,8 +167,30 @@
                 group->addAction(action);
             }
         }
+
+        bool isMenuTitle = map.take("x-kde-title").toBool();
+
         updateAction(action, map, map.keys());
 
+        if (isMenuTitle) {
+            QAction *buttonAction = action;
+            QFont font = buttonAction->font();
+            font.setBold(true);
+            buttonAction->setFont(font);
+            buttonAction->setEnabled(true);
+
+            QWidgetAction *action = new QWidgetAction(parent);
+            action->setObjectName("kmenu_title");
+            QToolButton *titleButton = new QToolButton(0);
+            EventSniffer *eventSniffer = new EventSniffer(titleButton);
+            titleButton->installEventFilter(eventSniffer); // prevent clicks on the title of the menu
+            titleButton->setDefaultAction(buttonAction);
+            titleButton->setDown(true); // prevent hover style changes in some styles
+            titleButton->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);
+            action->setDefaultWidget(titleButton);
+            return action;
+        }
+
         return action;
     }
 
