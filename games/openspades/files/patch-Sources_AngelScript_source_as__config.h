--- Sources/AngelScript/source/as_config.h.orig	2019-09-17 11:18:51 UTC
+++ Sources/AngelScript/source/as_config.h
@@ -947,6 +947,8 @@
 			#define COMPLEX_RETURN_MASK (asOBJ_APP_CLASS_DESTRUCTOR | asOBJ_APP_CLASS_COPY_CONSTRUCTOR | asOBJ_APP_ARRAY)
 			#define THISCALL_PASS_OBJECT_POINTER_ON_THE_STACK
 			#define AS_X86
+		#elif defined(__powerpc64__)
+			#define AS_MAX_PORTABILITY
 		#elif defined(__LP64__)
 			#define AS_X64_GCC
 			#define HAS_128_BIT_PRIMITIVES
