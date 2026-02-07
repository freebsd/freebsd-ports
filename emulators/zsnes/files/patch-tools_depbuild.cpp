--- tools/depbuild.cpp.orig	2006-12-27 06:04:05.000000000 -0500
+++ tools/depbuild.cpp	2014-06-09 23:45:07.000000000 -0400
@@ -29,6 +29,8 @@
 #include "fileutil.h"
 #include "strutil.h"
 
+#include <unistd.h>
+
 string cc;
 string nasm;
 string cflags;
