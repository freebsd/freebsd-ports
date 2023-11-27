FreeBSD's alloca(3) only needs <stdlib.h>

--- src/common/byte_stream.cpp.orig	2023-10-16 12:57:57 UTC
+++ src/common/byte_stream.cpp
@@ -28,7 +28,9 @@
 #ifdef _MSC_VER
 #include <malloc.h>
 #else
+#if !defined(__FreeBSD__)
 #include <alloca.h>
+#endif
 #endif
 
 Log_SetChannel(ByteStream);
