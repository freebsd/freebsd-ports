--- src/openexr/openexr.cpp.orig	2008-11-26 05:21:13 UTC
+++ src/openexr/openexr.cpp
@@ -35,6 +35,7 @@
 #include <string.h>
 #include <math.h>
 
+#include <ImfFrameBuffer.h>
 #include <ImfOutputFile.h>
 #include <ImfChannelList.h>
 #include <ImfStringAttribute.h>
