--- libs/JUCE/modules/juce_audio_processors/format_types/VST3_SDK/pluginterfaces/base/fplatform.h.orig	2024-07-14 16:47:34 UTC
+++ libs/JUCE/modules/juce_audio_processors/format_types/VST3_SDK/pluginterfaces/base/fplatform.h
@@ -128,7 +128,7 @@
 //-----------------------------------------------------------------------------
 // LINUX
 //-----------------------------------------------------------------------------
-#elif __gnu_linux__ || __linux__
+#elif __gnu_linux__ || __linux__ || defined(__FreeBSD__)
 	#define SMTG_OS_LINUX		1
 	#define SMTG_OS_MACOS		0
 	#define SMTG_OS_WINDOWS		0
@@ -150,7 +150,7 @@
 	#endif
 	#define SMTG_CPU_ARM_64EC 0
 
-	#include <endian.h>
+	#include <sys/endian.h>
 	#if __BYTE_ORDER == __LITTLE_ENDIAN
 		#define BYTEORDER kLittleEndian
 	#else
