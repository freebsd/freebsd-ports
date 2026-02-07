--- src/VBox/Devices/Graphics/DevVGA-SVGA3d-glLdr.cpp.orig	2025-04-14 17:55:41 UTC
+++ src/VBox/Devices/Graphics/DevVGA-SVGA3d-glLdr.cpp
@@ -196,7 +196,7 @@ int glLdrInit(PPDMDEVINS pDevIns)
     pfn_wglDeleteContext = 0;
     pfn_wglMakeCurrent = 0;
     pfn_wglShareLists = 0;
-#elif defined(RT_OS_LINUX)
+#elif defined(RT_OS_FREEBSD) || defined(RT_OS_LINUX)
     pfn_XConfigureWindow = 0;
     pfn_XCloseDisplay = 0;
     pfn_XCreateColormap = 0;
@@ -306,7 +306,7 @@ int glLdrInit(PPDMDEVINS pDevIns)
     GLGETPROC_(wglDeleteContext, "");
     GLGETPROC_(wglMakeCurrent, "");
     GLGETPROC_(wglShareLists, "");
-#elif defined(RT_OS_LINUX)
+#elif defined(RT_OS_FREEBSD) || defined(RT_OS_LINUX)
     X11GETPROC_(XConfigureWindow);
     X11GETPROC_(XCloseDisplay);
     X11GETPROC_(XCreateColormap);
@@ -407,7 +407,7 @@ int glLdrInit(PPDMDEVINS pDevIns)
     GLGETPROC_(glVertexPointer, "");
     GLGETPROC_(glViewport, "");
 
-#ifdef RT_OS_LINUX
+#if defined(RT_OS_FREEBSD) || defined(RT_OS_LINUX)
     XInitThreads();
 #endif
     return VINF_SUCCESS;
