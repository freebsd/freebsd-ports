--- quakedef.h.orig	2020-09-30 11:25:10 UTC
+++ quakedef.h
@@ -74,11 +74,6 @@ void	VID_UnlockBuffer (void);
 
 #endif
 
-//PENTA: win32 we use assembler
-#if defined(_WIN32) || defined __glx__
-#define USE_ASM 1
-#endif
-
 #if defined(__i386__) && defined(USE_ASM)
 #define id386	1
 #else
