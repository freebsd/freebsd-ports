--- src/external/angelscript/sdk/angelscript/source/as_config.h.orig	2021-08-10 01:31:47 UTC
+++ src/external/angelscript/sdk/angelscript/source/as_config.h
@@ -1008,7 +1008,7 @@
 	// Free BSD
 	#elif defined(__FreeBSD__) || defined(__DragonFly__) || defined(__OpenBSD__)
 		#define AS_BSD
-		#if (defined(i386) || defined(__i386) || defined(__i386__)) && !defined(__LP64__)
+		#if (defined(i386) || defined(__i386) || defined(__i386__)) && !defined(__amd64__)
 			#undef COMPLEX_MASK
 			#define COMPLEX_MASK (asOBJ_APP_CLASS_DESTRUCTOR | asOBJ_APP_CLASS_COPY_CONSTRUCTOR | asOBJ_APP_ARRAY)
 			#undef COMPLEX_RETURN_MASK
