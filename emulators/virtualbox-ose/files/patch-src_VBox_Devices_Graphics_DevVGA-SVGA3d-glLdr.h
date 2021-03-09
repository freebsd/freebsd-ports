--- src/VBox/Devices/Graphics/DevVGA-SVGA3d-glLdr.h.orig	2021-01-07 15:39:17 UTC
+++ src/VBox/Devices/Graphics/DevVGA-SVGA3d-glLdr.h
@@ -338,7 +338,7 @@ GLPFN BOOL (WINAPI *pfn_wglMakeCurrent)(HDC, HGLRC);
 GLPFN BOOL (WINAPI *pfn_wglShareLists)(HGLRC, HGLRC);
 #define wglShareLists pfn_wglShareLists
 
-#elif defined(RT_OS_LINUX)
+#elif defined(RT_OS_FREEBSD) || defined(RT_OS_LINUX)
 /*
  * GLX
  */
