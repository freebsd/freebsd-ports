
$FreeBSD$

--- src/libFLAC/cpu.c.orig
+++ src/libFLAC/cpu.c
@@ -25,6 +25,11 @@
 #include <config.h>
 #endif
 
+#ifdef __FreeBSD__
+#include <sys/types.h>
+#include <sys/sysctl.h>
+#endif
+
 const unsigned FLAC__CPUINFO_IA32_CPUID_CMOV = 0x00008000;
 const unsigned FLAC__CPUINFO_IA32_CPUID_MMX = 0x00800000;
 const unsigned FLAC__CPUINFO_IA32_CPUID_FXSR = 0x01000000;
@@ -52,6 +57,15 @@
 
 #ifndef FLAC__SSE_OS
 		info->data.ia32.fxsr = info->data.ia32.sse = info->data.ia32.sse2 = false;
+#else
+#if defined(__FreeBSD__)
+		{
+			int sse;
+			size_t len = sizeof(sse);
+			if (sysctlbyname("hw.instruction_sse", &sse, &len, NULL, 0) || !sse)
+				info->data.ia32.fxsr = info->data.ia32.sse = info->data.ia32.sse2 = false;
+		}
+#endif
 #endif
 
 #ifdef FLAC__USE_3DNOW
