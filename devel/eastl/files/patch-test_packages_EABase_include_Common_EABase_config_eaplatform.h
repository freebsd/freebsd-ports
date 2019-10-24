--- test/packages/EABase/include/Common/EABase/config/eaplatform.h.orig	2019-10-23 16:31:46 UTC
+++ test/packages/EABase/include/Common/EABase/config/eaplatform.h
@@ -449,6 +449,11 @@
 		#define EA_PROCESSOR_POWERPC_32 1
 		#define EA_SYSTEM_BIG_ENDIAN 1
 		#define EA_PLATFORM_DESCRIPTION "BSD on PowerPC"
+	#elif defined(__arm__)
+		#define EA_ABI_ARM_LINUX 1  // a.k.a. "ARM eabi"
+		#define EA_PROCESSOR_ARM32 1
+		#define EA_SYSTEM_LITTLE_ENDIAN 1
+		#define EA_PLATFORM_DESCRIPTION "BSD on ARM"
 	#else
 		#error Unknown processor
 		#error Unknown endianness
