--- ./qcommon/qcommon.h.orig	Sat Sep 16 16:16:40 2006
+++ ./qcommon/qcommon.h	Sat Dec 16 17:28:37 2006
@@ -86,7 +86,8 @@
 
 #elif defined __FreeBSD__
 
-#define BUILDSTRING "FreeBSD"
+	#define BUILDSTRING "FreeBSD"
+	#define __cdecl
 
 	#ifdef __i386__
 		#define CPUSTRING "i386"
