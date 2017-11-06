--- src/misc/CAtomicCounter.h.orig	2013-02-10 06:35:02 UTC
+++ src/misc/CAtomicCounter.h
@@ -28,7 +28,7 @@
 	#define LINUX_ATOMIX
 	#include <asm/atomic.h>
 
-#elif defined(__GNUC__) && ((__GNUC__ * 100) + __GNUC_MINOR__) >= 405 && defined(__GXX_EXPERIMENTAL_CXX0X__)/*for now detect --std=c++0x.. will be removed later*/
+#elif defined(__clang__) || defined(__GNUC__) && ((__GNUC__ * 100) + __GNUC_MINOR__) >= 405 && defined(__GXX_EXPERIMENTAL_CXX0X__)/*for now detect --std=c++0x.. will be removed later*/
 
 	// gcc-4.5 uses the atomic header (c++v0)
 	#define STL_ATOMIX
