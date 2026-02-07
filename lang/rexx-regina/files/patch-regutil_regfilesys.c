--- regutil/regfilesys.c.orig	2019-10-06 06:19:40 UTC
+++ regutil/regfilesys.c
@@ -27,6 +27,8 @@
 #endif
 
 #include "regutil.h"
+
+#pragma clang diagnostic ignored "-Wpointer-sign"
 #include <errno.h>
 #ifdef __EMX__
 # include <sys/types.h>
