--- include/system/libcontext.h.orig	2017-03-08 13:29:09.028153000 +0100
+++ include/system/libcontext.h	2017-03-08 13:31:22.843111000 +0100
@@ -23,5 +23,5 @@
 
 
-#if defined(__GNUC__) || defined(__APPLE__)
+#if defined(__GNUC__) || defined(__APPLE__) || defined(__FreeBSD__)
 
     #define LIBCONTEXT_COMPILER_gcc
@@ -55,5 +55,5 @@
 	    #define LIBCONTEXT_CALL_CONVENTION __cdecl
 	#endif
-    #elif defined(__APPLE__) && defined(__MACH__)
+    #elif defined(__APPLE__) && defined(__MACH__) || defined(__FreeBSD__)
 	#if defined (__i386__)
 	    #define LIBCONTEXT_PLATFORM_apple_i386
@@ -62,4 +62,7 @@
 	    #define LIBCONTEXT_PLATFORM_apple_x86_64
 	    #define LIBCONTEXT_CALL_CONVENTION
+	#elif defined (__amd64__)
+	    #define LIBCONTEXT_PLATFORM_apple_x86_64
+	    #define LIBCONTEXT_CALL_CONVENTION
 	#endif
     #endif
