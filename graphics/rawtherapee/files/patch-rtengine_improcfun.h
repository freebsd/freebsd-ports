--- ./rtengine/improcfun.h.orig	2012-01-31 05:00:05.000000000 +0400
+++ ./rtengine/improcfun.h	2012-03-30 23:15:22.000000000 +0400
@@ -18,6 +18,9 @@
  */
 #ifndef _IMPROCFUN_H_
 #define _IMPROCFUN_H_
+#ifndef log2(x)
+#define log2(x) (log(x)/log(2))
+#endif
 
 #include "imagefloat.h"
 #include "image16.h"
