--- showimg/qtiffio.cpp.orig	Fri Aug  1 15:29:41 2003
+++ showimg/qtiffio.cpp	Fri Aug  1 15:31:45 2003
@@ -17,6 +17,7 @@
 // 
 
 #include <stdio.h>
+#include <sys/types.h>
 #include <sys/mman.h>
 
 #include <tiffio.h>
