--- ./qcommon/qcommon.h.orig	Wed Mar 15 17:18:50 2006
+++ ./qcommon/qcommon.h	Wed May 17 22:31:34 2006
@@ -88,6 +88,7 @@
 
 #define BUILDSTRING "FreeBSD"
 
+	#define __cdecl
 	#ifdef __i386__
 		#define CPUSTRING "i386"
 	#elif defined __x86_64__
