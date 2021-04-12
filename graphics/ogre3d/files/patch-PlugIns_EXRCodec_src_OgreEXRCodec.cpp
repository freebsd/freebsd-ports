--- PlugIns/EXRCodec/src/OgreEXRCodec.cpp.orig	2019-04-24 16:21:46 UTC
+++ PlugIns/EXRCodec/src/OgreEXRCodec.cpp
@@ -42,6 +42,9 @@ THE SOFTWARE.
 #include <ImfStringAttribute.h>
 #include <ImfMatrixAttribute.h>
 #include <ImfArray.h>
+#include <ImathBox.h>
+#include <ImfHeader.h>
+#include <ImfFrameBuffer.h>
 
 using namespace Imath;
 using namespace Imf;
