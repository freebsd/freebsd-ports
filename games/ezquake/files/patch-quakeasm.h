--- quakeasm.h.orig	Tue Jul  5 17:01:34 2005
+++ quakeasm.h	Thu Aug 31 17:29:32 2006
@@ -25,12 +25,6 @@
 #define __i386__	1
 #endif
 
-#ifdef	__i386__
-#define id386	1
-#else
-#define id386	0
-#endif
-
 #ifndef SERVERONLY
 
 // !!! must be kept the same as in d_iface.h !!!
