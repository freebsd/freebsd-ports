--- ./ref_shared/qgl.c.orig	Mon Dec 25 17:07:02 2006
+++ ./ref_shared/qgl.c	Mon Dec 25 17:07:03 2006
@@ -392,7 +392,7 @@
 BOOL ( WINAPI * qwglSwapIntervalEXT )( int interval );
 #endif
 
-#ifdef __linux
+#ifdef __unix__
 void *qwglGetProcAddress( const char *symbol ) { return video.GetProcAddr( symbol ); }
 void (*qgl3DfxSetPaletteEXT)(GLuint *);
 #endif
