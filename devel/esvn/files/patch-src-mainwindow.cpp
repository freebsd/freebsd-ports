--- mainwindow.cpp.orig	Sun Aug 22 02:22:34 2004
+++ src/mainwindow.cpp	Mon Aug 23 18:44:41 2004
@@ -16,6 +16,7 @@
 
 #include "mainwindow.h"
 
+#include <unistd.h>
 #include <qlistview.h>
 #include <qtextcodec.h> 
 #include <qsocket.h>
