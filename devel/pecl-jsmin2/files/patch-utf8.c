--- utf8.c.orig	2015-11-19 03:00:13 UTC
+++ utf8.c
@@ -18,8 +18,6 @@
 #include <stdarg.h>
 #ifdef WIN32
 #include <malloc.h>
-#else
-#include <alloca.h>
 #endif
 
 #ifdef WIN32
