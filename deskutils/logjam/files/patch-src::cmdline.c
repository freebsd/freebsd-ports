--- src/cmdline.c.orig	Wed Mar 31 05:03:06 2004
+++ src/cmdline.c	Mon May 10 00:19:23 2004
@@ -13,6 +13,7 @@
 #endif
 
 #ifdef HAVE_REGEX_H
+#include <sys/types.h>
 #include <regex.h>
 #endif
 
