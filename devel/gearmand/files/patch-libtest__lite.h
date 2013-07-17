--- ./libtest/lite.h.orig	2013-05-03 00:58:08.000000000 -0400
+++ ./libtest/lite.h	2013-07-17 10:46:57.000000000 -0400
@@ -53,6 +53,8 @@
 
 #if defined(WIN32)
 # include <malloc.h>
+#elif defined(__FreeBSD__)
+# include <stdlib.h>
 #else
 # include <alloca.h>
 #endif
