--- Sources/SmallJPEG/jpgd/jidctfst.cpp.orig	Fri Jan 23 15:46:14 2004
+++ Sources/SmallJPEG/jpgd/jidctfst.cpp	Fri Jan 23 15:46:25 2004
@@ -1,4 +1,5 @@
 #include "jpegdecoder.h"
+#include <inttypes.h>
 
 #ifdef WIN32
 #pragma warning(push)
