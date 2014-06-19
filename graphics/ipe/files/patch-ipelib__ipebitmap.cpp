--- ipelib/ipebitmap.cpp.orig
+++ ipelib/ipebitmap.cpp
@@ -32,10 +32,16 @@
 #include "ipeutils.h"
 #include <zlib.h>
 
+#if 0
 #include <turbojpeg.h>
+#endif
 
 using namespace ipe;
 
+#if 1
+extern bool dctDecode(Buffer dctData, Buffer pixelData);
+#endif
+
 // --------------------------------------------------------------------
 
 /*! \class ipe::Bitmap::MRenderData
@@ -331,6 +337,7 @@
 
 // --------------------------------------------------------------------
 
+#if 0
 bool dctDecode(Buffer dctData, Buffer pixelData, int components)
 {
   tjhandle handle = tjInitDecompress();
@@ -363,6 +370,7 @@
   tjDestroy(handle);
   return true;
 }
+#endif
 
 //! Convert bitmap data to a height x width pixel array in rgb format.
 /*! Returns empty buffer if it cannot decode the bitmap information.
@@ -387,7 +395,11 @@
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
