--- src/mesa/main/macros.h.orig	2010-10-19 08:03:53.000000000 +0000
+++ src/mesa/main/macros.h	2010-10-19 08:05:32.000000000 +0000
@@ -33,6 +33,7 @@
 
 #include "imports.h"
 
+#define log2(x) (log(x) / log(2))
 
 /**
  * \name Integer / float conversion for colors, normals, etc.
