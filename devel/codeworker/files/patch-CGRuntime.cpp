--- CGRuntime.cpp.orig	Wed Dec 31 09:56:40 2003
+++ CGRuntime.cpp	Wed Dec 31 09:57:16 2003
@@ -60,6 +60,10 @@
 #	endif
 #	include "UtlString.h" // for Debian/gcc 2.95.4
 #endif
+
+#if defined(__FreeBSD__)
+	extern char **environ;
+#endif
 
 
 #ifndef WIN32
