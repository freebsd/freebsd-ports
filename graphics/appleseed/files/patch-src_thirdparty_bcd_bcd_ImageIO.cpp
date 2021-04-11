--- src/thirdparty/bcd/bcd/ImageIO.cpp.orig	2019-08-31 15:49:01 UTC
+++ src/thirdparty/bcd/bcd/ImageIO.cpp
@@ -30,6 +30,7 @@
     #include <OpenEXR/ImfFrameBuffer.h>
     #include <OpenEXR/ImfInputFile.h>
     #include <OpenEXR/ImfOutputFile.h>
+    #include <OpenEXR/ImfHeader.h>
 
 #if __GNUC__ >= 7
     #pragma GCC diagnostic pop
