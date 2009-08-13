--- dependencies/angelscript/source/as_config.h.orig	2009-08-13 00:22:24.000000000 +0400
+++ dependencies/angelscript/source/as_config.h	2009-08-13 00:22:44.000000000 +0400
@@ -470,6 +470,7 @@
 			#define AS_MAX_PORTABILITY
 		#endif
 		#define AS_POSIX_THREADS
+		#define AS_NO_ATOMIC
 
 	// PSP and PS2
 	#elif defined(__PSP__) || defined(__psp__) || defined(_EE_) || defined(_PSP) || defined(_PS2)
