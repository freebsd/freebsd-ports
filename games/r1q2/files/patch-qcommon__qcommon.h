--- qcommon/qcommon.h.orig	Mon Nov 19 03:50:37 2007
+++ qcommon/qcommon.h	Mon Nov 19 04:03:27 2007
@@ -86,7 +86,8 @@
 
 #elif defined __FreeBSD__
 
-#define BUILDSTRING "FreeBSD"
+	#define BUILDSTRING "FreeBSD"
+	#define __cdecl
 
 	#ifdef __i386__
 		#define CPUSTRING "i386"
@@ -1079,7 +1080,8 @@
 	TAGMALLOC_CMDBANS,
 	TAGMALLOC_REDBLACK,
 	TAGMALLOC_LRCON,
-#ifdef ANTICHEAT
+//#ifdef ANTICHEAT
+#if 1 // always used in sv_main.c, when building client and ANTICHEAT is 0
 	TAGMALLOC_ANTICHEAT,
 #endif
 	TAGMALLOC_MAX_TAGS
