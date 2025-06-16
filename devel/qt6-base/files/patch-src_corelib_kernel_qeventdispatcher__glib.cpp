https://codereview.qt-project.org/c/qt/qtbase/+/651677

--- src/corelib/kernel/qeventdispatcher_glib.cpp.orig	2025-02-13 17:45:28 UTC
+++ src/corelib/kernel/qeventdispatcher_glib.cpp
@@ -434,10 +434,10 @@ void QEventDispatcherGlib::registerSocketNotifier(QSoc
         p->pollfd.events = G_IO_IN | G_IO_HUP | G_IO_ERR;
         break;
     case QSocketNotifier::Write:
-        p->pollfd.events = G_IO_OUT | G_IO_ERR;
+        p->pollfd.events = G_IO_OUT | G_IO_HUP | G_IO_ERR;
         break;
     case QSocketNotifier::Exception:
-        p->pollfd.events = G_IO_PRI | G_IO_ERR;
+        p->pollfd.events = G_IO_PRI | G_IO_HUP | G_IO_ERR;
         break;
     }
     p->socketNotifier = notifier;
