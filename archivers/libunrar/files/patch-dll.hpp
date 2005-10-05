--- dll.hpp.orig  2004-09-08 17:57:20.000000000 +0400
+++ dll.hpp       2004-10-22 10:43:08.000000000 +0400
@@ -26,13 +26,13 @@
 
 #define RAR_DLL_VERSION       4
 
-#ifdef _UNIX
+//#ifdef _UNIX
 #define CALLBACK
 #define PASCAL
 #define LONG long
 #define HANDLE void *
 #define UINT unsigned int
-#endif
+//#endif
 
 struct RARHeaderData
 {
