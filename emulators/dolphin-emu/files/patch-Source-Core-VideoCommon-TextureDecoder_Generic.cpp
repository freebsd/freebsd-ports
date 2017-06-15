Add missing header for memset()

--- Source/Core/VideoCommon/TextureDecoder_Generic.cpp.orig	2016-12-02 08:01:14.838668401 +0000
+++ Source/Core/VideoCommon/TextureDecoder_Generic.cpp	2016-12-02 08:01:28.081034936 +0000
@@ -4,6 +4,7 @@
 
 #include <algorithm>
 #include <cmath>
+#include <cstring>
 
 #include "Common/CommonFuncs.h"
 #include "Common/CommonTypes.h"
