--- src/ref_candygl/qgl.h.orig	2002-06-17 20:03:07 UTC
+++ src/ref_candygl/qgl.h
@@ -30,7 +30,7 @@ Foundation, Inc., 59 Temple Place - Suit
 
 #include <GL/gl.h>
 
-#ifdef __linux__
+#ifndef _WIN32
 //#include <GL/fxmesa.h>
 #include <GL/glx.h>
 #endif
@@ -428,9 +428,7 @@ extern BOOL ( WINAPI * qwglSwapIntervalE
 extern BOOL ( WINAPI * qwglGetDeviceGammaRampEXT ) ( unsigned char *pRed, unsigned char *pGreen, unsigned char *pBlue );
 extern BOOL ( WINAPI * qwglSetDeviceGammaRampEXT ) ( const unsigned char *pRed, const unsigned char *pGreen, const unsigned char *pBlue );
 
-#endif
-
-#ifdef __linux__
+#else
 
 // local function in dll
 extern void *qwglGetProcAddress(char *symbol);
