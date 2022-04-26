--- libs/JUCE/modules/juce_audio_processors/format_types/VST3_SDK/pluginterfaces/base/fplatform.h.orig	2022-02-23 15:06:22 UTC
+++ libs/JUCE/modules/juce_audio_processors/format_types/VST3_SDK/pluginterfaces/base/fplatform.h
@@ -19,7 +19,7 @@
 #define kLittleEndian	0
 #define kBigEndian		1
 
-#undef PLUGIN_API
+//#undef PLUGIN_API
 
 #if !defined (__INTEL_CXX11_MODE__)
 #define SMTG_INTEL_CXX11_MODE 0
@@ -95,7 +95,7 @@
 //-----------------------------------------------------------------------------
 // LINUX
 //-----------------------------------------------------------------------------
-#elif __gnu_linux__ || __linux__
+#elif __gnu_linux__ || __linux__ || defined(__FreeBSD__)
 	#define SMTG_OS_LINUX	1
 	#define SMTG_OS_MACOS	0
 	#define SMTG_OS_WINDOWS	0
@@ -107,7 +107,7 @@
 	#define SMTG_CPU_ARM	__arm__
 	#define SMTG_CPU_ARM_64	__aarch64__
 
-	#include <endian.h>
+	#include <sys/endian.h>
 	#if __BYTE_ORDER == __LITTLE_ENDIAN
 		#define BYTEORDER kLittleEndian
 	#else
