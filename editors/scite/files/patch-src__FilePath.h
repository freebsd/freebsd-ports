--- ../src/FilePath.h.orig	2011-07-31 22:49:30.000000000 -0400
+++ ../src/FilePath.h	2011-09-06 21:43:03.000000000 -0400
@@ -13,6 +13,7 @@
 extern const GUI::gui_char fileWrite[];
 
 #if defined(__unix__)
+#include <cstdio>
 #include <limits.h>
 #ifdef PATH_MAX
 #define MAX_PATH PATH_MAX
