--- Source/BigInt.cpp.orig	2009-03-24 19:01:02.367310998 +0000
+++ Source/BigInt.cpp	2009-03-24 19:02:28.108157600 +0000
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
