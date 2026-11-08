-- Add FreeBSD to the Linux platform branch and use sys/endian.h instead of endian.h.
-- The VST3 SDK does not natively support FreeBSD, so reuse the Linux code path.

--- src/vst3/pluginterfaces/base/fplatform.h.orig	2026-09-06 17:42:39 UTC
+++ src/vst3/pluginterfaces/base/fplatform.h
@@ -126,7 +126,7 @@
 //-----------------------------------------------------------------------------
 // LINUX
 //-----------------------------------------------------------------------------
-#elif (defined (__gnu_linux__) && __gnu_linux__) || (defined (__linux__) && __linux__)
+#elif (defined (__gnu_linux__) && __gnu_linux__) || (defined (__linux__) && __linux__) || defined (__FreeBSD__)
 	#define SMTG_OS_LINUX		1
 	#define SMTG_OS_MACOS		0
 	#define SMTG_OS_WINDOWS		0
@@ -156,7 +156,7 @@
 	#endif
 	#define SMTG_CPU_ARM_64EC 0
 
-	#include <endian.h>
+	#include <sys/endian.h>
 	#if __BYTE_ORDER == __LITTLE_ENDIAN
 		#define BYTEORDER kLittleEndian
 	#else
