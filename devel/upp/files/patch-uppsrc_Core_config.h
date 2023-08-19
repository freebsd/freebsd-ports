--- uppsrc/Core/config.h.orig	2023-08-19 14:40:16 UTC
+++ uppsrc/Core/config.h
@@ -139,6 +139,16 @@
 		#define _HAVE_NO_STDWSTRING 1
 		//BF toolchain has no support for __thread (TLS), so U++ Heap not possible
 		#define flagUSEMALLOC
+	#elif __powerpc64__
+		#define CPU_64 1
+		#define CPU_UNALIGNED 1
+		#if __BYTE_ORDER__ == __ORDER_LITTLE_ENDIAN__
+			#define CPU_LE 1
+			#define CPU_LITTLE_ENDIAN 1
+		#else
+			#define CPU_BE 1
+			#define CPU_BIG_ENDIAN 1
+		#endif
 	#else
 		#error Unknown CPU architecture
 	#endif
