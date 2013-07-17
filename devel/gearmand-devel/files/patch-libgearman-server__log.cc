--- ./libgearman-server/log.cc.orig	2013-06-05 15:55:41.000000000 -0400
+++ ./libgearman-server/log.cc	2013-07-17 14:33:54.000000000 -0400
@@ -56,6 +56,8 @@
 
 #ifdef _WIN32
 # include <malloc.h>
+#elif defined(__FreeBSD__)
+# include <stdlib.h>
 #else
 # include <alloca.h>
 #endif
