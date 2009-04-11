--- Source/RSACrypt.cpp.orig	2009-03-26 07:12:50.774873901 +0000
+++ Source/RSACrypt.cpp	2009-03-26 07:14:10.613249169 +0000
@@ -5,7 +5,9 @@
 #if defined(_WIN32)
 #include <malloc.h> // alloca
 #elif (defined(__GNUC__)  || defined(__GCCXML__))
+#if !defined ( __FreeBSD__ )
 #include <alloca.h>
+#endif
 #else
 #endif
 #include "RakMemoryOverride.h"
