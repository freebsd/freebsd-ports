--- modules/juce_audio_processors/format_types/VST3_SDK/pluginterfaces/base/fplatform.h.orig	2023-01-25 11:45:10 UTC
+++ modules/juce_audio_processors/format_types/VST3_SDK/pluginterfaces/base/fplatform.h
@@ -139,6 +139,43 @@
 		#define SMTG_HAS_NOEXCEPT 1
 	#endif
 //-----------------------------------------------------------------------------
+// BSD
+//-----------------------------------------------------------------------------
+#elif __FreeBSD__
+	#define SMTG_OS_LINUX	1 // atomic operations need to be implemented
+	#define SMTG_OS_MACOS	0
+	#define SMTG_OS_WINDOWS	0
+	#define SMTG_OS_IOS		0
+	#define SMTG_OS_OSX		0
+
+	#include <sys/endian.h>
+	#if __BYTE_ORDER == __LITTLE_ENDIAN
+		#define BYTEORDER kLittleEndian
+	#else
+		#define BYTEORDER kBigEndian
+	#endif
+
+	#define COM_COMPATIBLE	0
+	#define PLUGIN_API
+	#define SMTG_PTHREADS	1
+
+	#define SMTG_EXPORT_SYMBOL __attribute__ ((visibility ("default")))
+
+	#if __LP64__
+		#define SMTG_PLATFORM_64 1
+	#else
+		#define SMTG_PLATFORM_64 0
+	#endif
+	#ifdef __cplusplus
+		#include <cstddef>
+		#define SMTG_CPP11 (__cplusplus >= 201103L)
+		#ifndef SMTG_CPP11
+			#error unsupported compiler
+		#endif
+		#define SMTG_CPP11_STDLIBSUPPORT 1
+		#define SMTG_HAS_NOEXCEPT 1
+	#endif
+//-----------------------------------------------------------------------------
 // Mac and iOS
 //-----------------------------------------------------------------------------
 #elif __APPLE__
