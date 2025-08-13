--- thirdparty/jolt_physics/Jolt/Core/Core.h.orig	2025-08-13 15:24:56 UTC
+++ thirdparty/jolt_physics/Jolt/Core/Core.h
@@ -215,7 +215,7 @@
 		#define JPH_CPU_BIG_ENDIAN
 	#endif
 	#define JPH_VECTOR_ALIGNMENT 16
-	#define JPH_DVECTOR_ALIGNMENT 8
+	#define JPH_DVECTOR_ALIGNMENT 16
 #elif defined(__loongarch__)
 	// LoongArch CPU architecture
 	#define JPH_CPU_LOONGARCH
