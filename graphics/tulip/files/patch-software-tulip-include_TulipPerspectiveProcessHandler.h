--- software/tulip/include/TulipPerspectiveProcessHandler.h.orig	2014-04-18 11:41:35.000000000 +0200
+++ software/tulip/include/TulipPerspectiveProcessHandler.h	2014-04-18 11:47:38.000000000 +0200
@@ -27,6 +27,8 @@
 
 #include <QTcpServer>
 
+#include <ctime>
+
 // Some utility class used in crash handler dialog designer form
 
 class SelectionButton: public QPushButton {
