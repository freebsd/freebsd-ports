--- thirdparty/jolt_physics/Jolt/Core/Core.h.orig	2025-10-13 19:05:40 UTC
+++ thirdparty/jolt_physics/Jolt/Core/Core.h
@@ -219,7 +219,7 @@
 		#define JPH_CPU_BIG_ENDIAN
 	#endif
 	#define JPH_VECTOR_ALIGNMENT 16
-	#define JPH_DVECTOR_ALIGNMENT 8
+	#define JPH_DVECTOR_ALIGNMENT 16
 #elif defined(__loongarch__)
 	// LoongArch CPU architecture
 	#define JPH_CPU_LOONGARCH
