--- sublib/MsgHandler.cpp.orig	2007-08-19 22:04:03.000000000 +0900
+++ sublib/MsgHandler.cpp	2012-05-10 05:58:52.000000000 +0900
@@ -16,6 +16,9 @@
 // qt
 #include <QtGui/QApplication>
 
+// sys
+#include <cstdlib>
+
 
 static void MessageHandler( QtMsgType type, const char *msg )
 {
@@ -28,6 +31,7 @@
     msgWarning( getLongAppName(), msg, _q("&Ok") );
     break;
   case QtFatalMsg:
+  case QtCriticalMsg:
     msgCritical( getLongAppName(), msg, _q("&Abort") );
     abort();
   }
