--- plugins/vst/external/VST_SDK/VST3_SDK/pluginterfaces/base/fplatform.h.orig	2022-07-27 05:18:10 UTC
+++ plugins/vst/external/VST_SDK/VST3_SDK/pluginterfaces/base/fplatform.h
@@ -95,7 +95,7 @@
 //-----------------------------------------------------------------------------
 // LINUX
 //-----------------------------------------------------------------------------
-#elif __gnu_linux__ || __linux__
+#elif __gnu_linux__ || __linux__ || __FreeBSD__
 	#define SMTG_OS_LINUX	1
 	#define SMTG_OS_MACOS	0
 	#define SMTG_OS_WINDOWS	0
@@ -107,7 +107,11 @@
 	#define SMTG_CPU_ARM	__arm__
 	#define SMTG_CPU_ARM_64	__aarch64__
 
+#  ifdef __FreeBSD__
+	#include <sys/endian.h>
+#  else
 	#include <endian.h>
+#  endif
 	#if __BYTE_ORDER == __LITTLE_ENDIAN
 		#define BYTEORDER kLittleEndian
 	#else
