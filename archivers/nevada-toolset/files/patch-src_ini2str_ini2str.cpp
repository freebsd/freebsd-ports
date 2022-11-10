--- src/ini2str/ini2str.cpp.orig	2020-08-15 22:06:32 UTC
+++ src/ini2str/ini2str.cpp
@@ -20,6 +20,7 @@
 #include "endiantype.h"
 #include "rawfile.h"
 #include "strini.h"
+#include <cstdio>
 #include <win32compat.h>
 
 char g_LineBreak = '`';
