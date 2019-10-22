diff --git sdk/angelscript/source/as_config.h sdk/angelscript/source/as_config.h
index e17d1ee..f0e49b4 100644
--- ../../source/as_config.h
+++ ../../source/as_config.h
@@ -953,7 +953,9 @@
 			#define COMPLEX_RETURN_MASK (asOBJ_APP_CLASS_DESTRUCTOR | asOBJ_APP_CLASS_COPY_CONSTRUCTOR | asOBJ_APP_ARRAY)
 			#define THISCALL_PASS_OBJECT_POINTER_ON_THE_STACK
 			#define AS_X86
-		#elif defined(__x86_64__)
+		#elif defined(__powerpc64__)
+			#define AS_MAX_PORTABILITY
+		#elif defined(__x86_64__) || defined(__LP64__)
 			#define AS_X64_GCC
 			#define HAS_128_BIT_PRIMITIVES
 			#define SPLIT_OBJS_BY_MEMBER_TYPES
