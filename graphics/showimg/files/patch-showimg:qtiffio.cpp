--- showimg/qtiffio.cpp.orig	Sun Apr 14 11:53:48 2002
+++ showimg/qtiffio.cpp	Sun Apr 14 11:54:01 2002
@@ -17,6 +17,7 @@
 // 
 
 #include <stdio.h>
+#include <sys/types.h>
 #include <sys/mman.h>
 
 #include <tiffio.h>
