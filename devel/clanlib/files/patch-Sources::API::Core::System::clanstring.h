--- Sources/API/Core/System/clanstring.h.orig	Thu Jan 22 13:11:58 2004
+++ Sources/API/Core/System/clanstring.h	Thu Jan 22 13:12:12 2004
@@ -39,7 +39,7 @@
 #include <extras.h>
 #endif
 
-#ifdef __MACOS__
+#if defined(__MACOS__) || defined(__FreeBSD__)
 #include <cctype>
 #define NEED_FCVT
 #endif
