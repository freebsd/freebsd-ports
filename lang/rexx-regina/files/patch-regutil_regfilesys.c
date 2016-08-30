--- regutil/regfilesys.c.orig	2015-04-04 08:16:55 UTC
+++ regutil/regfilesys.c
@@ -27,6 +27,8 @@
 #endif
 
 #include "regutil.h"
+
+#pragma clang diagnostic ignored "-Wpointer-sign"
 #include <errno.h>
 #ifdef __EMX__
 # include <sys/types.h>
