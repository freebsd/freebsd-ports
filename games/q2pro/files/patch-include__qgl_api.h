--- ./include/qgl_api.h.orig	Mon Dec 25 17:07:02 2006
+++ ./include/qgl_api.h	Mon Dec 25 17:07:02 2006
@@ -392,7 +392,7 @@
 typedef BOOL ( WINAPI * PFNWGLSWAPINTERWALEXTPROC )( int );
 extern PROC ( WINAPI * qwglGetProcAddress )( LPCSTR );
 extern BOOL ( WINAPI * qwglSwapIntervalEXT )( int interval );
-#elif ( defined __linux__ )
+#elif ( defined __FreeBSD__ )
 // local function in dll
 extern void *qwglGetProcAddress( const char *symbol );
 extern void (*qgl3DfxSetPaletteEXT)(GLuint *);
