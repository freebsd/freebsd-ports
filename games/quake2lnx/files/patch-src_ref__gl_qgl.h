--- src/ref_gl/qgl.h.orig	2004-05-02 19:36:53 UTC
+++ src/ref_gl/qgl.h
@@ -426,9 +426,7 @@ extern BOOL ( WINAPI * qwglSwapIntervalE
 extern BOOL ( WINAPI * qwglGetDeviceGammaRampEXT ) ( unsigned char *pRed, unsigned char *pGreen, unsigned char *pBlue );
 extern BOOL ( WINAPI * qwglSetDeviceGammaRampEXT ) ( const unsigned char *pRed, const unsigned char *pGreen, const unsigned char *pBlue );
 
-#endif
-
-#ifdef __linux__
+#else
 
 // local function in dll
 extern void *qwglGetProcAddress(char *symbol);
