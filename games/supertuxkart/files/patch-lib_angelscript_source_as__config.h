--- lib/angelscript/source/as_config.h.orig	2019-07-11 00:36:27 UTC
+++ lib/angelscript/source/as_config.h
@@ -953,7 +953,7 @@
 			#define COMPLEX_RETURN_MASK (asOBJ_APP_CLASS_DESTRUCTOR | asOBJ_APP_CLASS_COPY_CONSTRUCTOR | asOBJ_APP_ARRAY)
 			#define THISCALL_PASS_OBJECT_POINTER_ON_THE_STACK
 			#define AS_X86
-		#elif defined(__LP64__)
+		#elif defined(__x86_64__)
 			#define AS_X64_GCC
 			#define HAS_128_BIT_PRIMITIVES
 			#define SPLIT_OBJS_BY_MEMBER_TYPES
