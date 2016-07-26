--- libmpio/debug.h.orig	2003-04-27 12:08:20 UTC
+++ libmpio/debug.h
@@ -41,7 +41,7 @@
 #ifdef sun
 #include <sys/int_types.h>
 #else
-#include <stdint.h>
+#include <sys/types.h>
 #endif
 
 #ifdef __cplusplus
