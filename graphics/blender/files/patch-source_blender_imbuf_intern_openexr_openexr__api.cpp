--- source/blender/imbuf/intern/openexr/openexr_api.cpp.orig	2020-11-25 08:31:32 UTC
+++ source/blender/imbuf/intern/openexr/openexr_api.cpp
@@ -38,6 +38,7 @@
 #include <ImfChannelList.h>
 #include <ImfCompression.h>
 #include <ImfCompressionAttribute.h>
+#include <ImfFrameBuffer.h>
 #include <ImfIO.h>
 #include <ImfInputFile.h>
 #include <ImfOutputFile.h>
@@ -94,6 +95,7 @@ _CRTIMP void __cdecl _invalid_parameter_noinfo(void)
 
 using namespace Imf;
 using namespace Imath;
+typedef uint64_t Int64;
 
 extern "C" {
 /* prototype */
