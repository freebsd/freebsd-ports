-- Add FreeBSD platform support to the VST3 SDK bundled with JUCE.
-- The upstream SDK only defines Linux/macOS/Windows platform macros,
-- so compilation on FreeBSD fails without an equivalent FreeBSD section.
-- We also enable SMTG_USE_STDATOMIC_H because the Linux __gnu_cxx atomics
-- are not available on FreeBSD.
--- modules/juce_audio_processors_headless/format_types/VST3_SDK/pluginterfaces/base/fplatform.h.orig	2026-07-21 03:18:06 UTC
+++ modules/juce_audio_processors_headless/format_types/VST3_SDK/pluginterfaces/base/fplatform.h
@@ -187,6 +187,66 @@
 		#define SMTG_HAS_CPP14_CONSTEXPR SMTG_CPP14
 	#endif // __cplusplus
 //-----------------------------------------------------------------------------
+// BSD
+//-----------------------------------------------------------------------------
+#elif __FreeBSD__
+	#define SMTG_OS_LINUX		1
+	#define SMTG_OS_MACOS		0
+	#define SMTG_OS_WINDOWS		0
+	#define SMTG_OS_WINDOWS_ARM	0
+	#define SMTG_OS_IOS			0
+	#define SMTG_OS_OSX			0
+
+	#define SMTG_CPU_X86	__i386__
+	#define SMTG_CPU_X86_64	__x86_64__
+	#if defined (__arm__)
+		#define SMTG_CPU_ARM	__arm__
+	#else
+		#define SMTG_CPU_ARM	0
+	#endif
+	#if defined (__aarch64__)
+		#define SMTG_CPU_ARM_64	__aarch64__
+	#else
+		#define SMTG_CPU_ARM_64	0
+	#endif
+	#define SMTG_CPU_ARM_64EC 0
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
+	#define SMTG_HIDDEN_SYMBOL __attribute__ ((visibility ("hidden")))
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
+		#define SMTG_CPP14 (__cplusplus >= 201402L)
+		#define SMTG_CPP17 (__cplusplus >= 201703L)
+		#define SMTG_CPP20 (__cplusplus >= 202002L)
+		#define SMTG_CPP23 (__cplusplus >= 202302L)
+		#define SMTG_USE_STDATOMIC_H 1
+		#define SMTG_CPP11_STDLIBSUPPORT 1
+		#define SMTG_HAS_NOEXCEPT 1
+		#define SMTG_HAS_CPP11_CONSTEXPR SMTG_CPP11
+		#define SMTG_HAS_CPP14_CONSTEXPR SMTG_CPP14
+	#endif // __cplusplus
+//-----------------------------------------------------------------------------
 // Mac and iOS
 //-----------------------------------------------------------------------------
 #elif __APPLE__
