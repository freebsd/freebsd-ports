--- ./src/q4wine-gui/process.h.orig	2013-11-10 13:35:22.000000000 +0100
+++ ./src/q4wine-gui/process.h	2013-11-14 00:37:10.000000000 +0100
@@ -31,6 +31,7 @@
 #include <QLibrary>
 #include <QTextCodec>
 #include <QTextStream>
+#include <locale.h>
 
 #ifdef DEBUG
 #include <QDebug>
