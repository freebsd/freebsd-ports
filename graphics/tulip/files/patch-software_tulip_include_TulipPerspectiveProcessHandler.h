--- software/tulip/include/TulipPerspectiveProcessHandler.h.orig	2015-04-18 20:15:52 UTC
+++ software/tulip/include/TulipPerspectiveProcessHandler.h
@@ -27,6 +27,8 @@
 
 #include <QTcpServer>
 
+#include <ctime>
+
 // Some utility class used in crash handler dialog designer form
 
 class SelectionButton: public QPushButton {
