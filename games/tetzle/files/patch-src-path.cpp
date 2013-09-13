--- src/path.cpp.orig	2013-02-28 21:57:04.000000000 +0400
+++ src/path.cpp	2013-09-13 05:27:35.631233459 +0400
@@ -24,6 +24,8 @@
 
 #include "path.h"
 
+#include <cstdlib> // for getenv()
+
 #include <QDesktopServices>
 #include <QDir>
 #include <QFile>
