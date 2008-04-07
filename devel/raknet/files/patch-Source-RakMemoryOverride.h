--- Source/RakMemoryOverride.h.orig	2008-03-18 21:46:43.000000000 +0100
+++ Source/RakMemoryOverride.h	2008-03-27 09:41:18.000000000 +0100
@@ -10,7 +10,9 @@
 #elif defined(_WIN32)
 #include <malloc.h>
 #else
+#if !defined ( __FreeBSD__ )
 #include <alloca.h>
+#endif
 #include <stdlib.h>
 #endif
 
