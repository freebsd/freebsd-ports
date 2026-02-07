--- src/VBox/Devices/Graphics/DevVGA-SVGA3d-dx-dx11.cpp.orig	2025-08-13 19:47:43 UTC
+++ src/VBox/Devices/Graphics/DevVGA-SVGA3d-dx-dx11.cpp
@@ -3021,7 +3021,7 @@ static DECLCALLBACK(int) vmsvga3dBackInit(PPDMDEVINS p
     RT_NOREF(pDevIns, pThis);
 
     int rc;
-#ifdef RT_OS_LINUX /** @todo Remove, this is currently needed for loading the X11 library in order to call XInitThreads(). */
+#if defined(RT_OS_FREEBSD) || defined(RT_OS_LINUX) /** @todo Remove, this is currently needed for loading the X11 library in order to call XInitThreads(). */
     rc = glLdrInit(pDevIns);
     if (RT_FAILURE(rc))
     {
