--- dll.hpp.orig	2010-03-15 06:30:53 UTC
+++ dll.hpp
@@ -28,14 +28,14 @@
 
 #define RAR_DLL_VERSION       4
 
-#ifdef _UNIX
+// #ifdef _UNIX
 #define CALLBACK
 #define PASCAL
 #define LONG long
 #define HANDLE void *
 #define LPARAM long
 #define UINT unsigned int
-#endif
+// #endif
 
 struct RARHeaderData
 {
