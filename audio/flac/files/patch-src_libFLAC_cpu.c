
$FreeBSD$

--- src/libFLAC/cpu.c.orig
+++ src/libFLAC/cpu.c
@@ -37,6 +37,11 @@
 #include <config.h>
 #endif
 
+#ifdef __FreeBSD__
+#include <sys/types.h>
+#include <sys/sysctl.h>
+#endif
+
 #if defined FLAC__CPU_PPC
 #if !defined FLAC__NO_ASM
 #if defined FLAC__SYS_DARWIN
@@ -95,6 +100,14 @@
 
 #ifndef FLAC__SSE_OS
 		info->data.ia32.fxsr = info->data.ia32.sse = info->data.ia32.sse2 = false;
+#elif defined(__FreeBSD__)
+		/* on FreeBSD we can double-check via sysctl whether the OS supports SSE */
+		{
+			int sse;
+			size_t len = sizeof(sse);
+			if (sysctlbyname("hw.instruction_sse", &sse, &len, NULL, 0) || !sse)
+				info->data.ia32.fxsr = info->data.ia32.sse = info->data.ia32.sse2 = false;
+		}
 #endif
 
 #ifdef FLAC__USE_3DNOW
