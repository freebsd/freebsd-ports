--- ./src/q4wine-gui/process.h.orig	2013-05-02 22:38:39.000000000 +0200
+++ ./src/q4wine-gui/process.h	2013-10-29 00:24:57.000000000 +0100
@@ -32,6 +32,7 @@
 #include <QLibrary>
 #include <QTextCodec>
 #include <QTextStream>
+#include <locale.h>
 
 #ifdef DEBUG
 #include <QDebug>
