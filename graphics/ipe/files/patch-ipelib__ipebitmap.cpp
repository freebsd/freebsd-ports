--- ipelib/ipebitmap.cpp.orig
+++ ipelib/ipebitmap.cpp
@@ -32,7 +32,9 @@
 #include "ipeutils.h"
 #include <zlib.h>
 
+#if 0
 #include <turbojpeg.h>
+#endif
 #include <png.h>
 
 using namespace ipe;
@@ -332,6 +334,7 @@
 
 // --------------------------------------------------------------------
 
+#if 0
 bool dctDecode(Buffer dctData, Buffer pixelData, int components)
 {
   tjhandle handle = tjInitDecompress();
@@ -364,6 +367,9 @@
   tjDestroy(handle);
   return true;
 }
+#else
+bool dctDecode(Buffer dctData, Buffer pixelData);
+#endif
 
 //! Convert bitmap data to a height x width pixel array in rgb format.
 /*! Returns empty buffer if it cannot decode the bitmap information.
@@ -388,7 +394,11 @@
       return Buffer();
   } else if (filter() == EDCTDecode) {
     pixels = Buffer(width() * height() * components());
+#if 0
     if (!dctDecode(stream, pixels, components()))
+#else
+    if (!dctDecode(stream, pixels))
+#endif
       return Buffer();
   }
   Buffer data(height() * width() * sizeof(uint));
