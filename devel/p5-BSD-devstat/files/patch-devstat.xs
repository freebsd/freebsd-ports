--- devstat.xs.orig	2010-04-04 16:46:31.614613328 +0900
+++ devstat.xs	2010-04-04 16:47:03.027043722 +0900
@@ -8,6 +8,7 @@
 #ifdef __cplusplus
 }
 #endif
+#include <sys/resource.h>
 #include <devstat.h>
 
 struct bsd_devstat {
