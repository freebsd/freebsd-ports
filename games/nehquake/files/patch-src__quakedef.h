--- src/quakedef.h.orig	2005-09-27 16:41:52 UTC
+++ src/quakedef.h
@@ -101,7 +101,7 @@ void	VID_UnlockBuffer (void);
 #define MAX_MSGLEN              65536 //8192            // max length of a reliable message
 #define MAX_DATAGRAM            65536 //3027            // max length of unreliable message
 
-#define	MAX_PRINTMSG		4096
+#define	MAX_PRINTMSG		16384
 
 //
 // per-level limits
@@ -337,7 +337,7 @@ void Chase_Reset (void);
 void Chase_Update (void);
 
 extern int bspversion;
-#ifdef __linux
+#ifdef __unix__
 #ifndef min
 #define min(a, b)  (((a) < (b)) ? (a) : (b))
 #endif
