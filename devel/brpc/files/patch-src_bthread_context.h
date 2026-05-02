--- src/bthread/context.h.orig	2026-02-23 02:11:29 UTC
+++ src/bthread/context.h
@@ -58,6 +58,15 @@
 	    #define BTHREAD_CONTEXT_CALL_CONVENTION __cdecl
 	#endif
 
+  #elif defined(__FreeBSD__)
+        #ifdef __x86_64__
+            #define BTHREAD_CONTEXT_PLATFORM_linux_x86_64
+            #define BTHREAD_CONTEXT_CALL_CONVENTION
+        #elif __aarch64__
+            #define BTHREAD_CONTEXT_PLATFORM_linux_arm64
+            #define BTHREAD_CONTEXT_CALL_CONVENTION
+        #endif
+
   #elif defined(__APPLE__) && defined(__MACH__)
 	#if defined (__i386__)
 	    #define BTHREAD_CONTEXT_PLATFORM_apple_i386
