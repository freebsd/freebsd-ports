--- src/image_handlers/exrHandler.cc.orig	2020-07-13 08:15:40 UTC
+++ src/image_handlers/exrHandler.cc
@@ -35,6 +35,8 @@
 #include <ImfVersion.h>
 #include <IexThrowErrnoExc.h>
 
+typedef uint64_t Int64;
+
 using namespace Imf;
 using namespace Imath;
 
