--- plugins/impex/exr/exr_converter.cc.orig	2020-10-28 11:42:28 UTC
+++ plugins/impex/exr/exr_converter.cc
@@ -24,6 +24,8 @@
 
 #include <ImfAttribute.h>
 #include <ImfChannelList.h>
+#include <ImfFrameBuffer.h>
+#include <ImfHeader.h>
 #include <ImfInputFile.h>
 #include <ImfOutputFile.h>
 
