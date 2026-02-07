--- src/VBox/Devices/Graphics/DevVGA-SVGA3d-ogl.cpp.orig	2025-04-14 17:55:42 UTC
+++ src/VBox/Devices/Graphics/DevVGA-SVGA3d-ogl.cpp
@@ -1198,7 +1198,7 @@ static DECLCALLBACK(int) vmsvga3dBackTerminate(PVGASTA
     RTSemEventDestroy(pState->WndRequestSem);
 #elif defined(RT_OS_DARWIN)
 
-#elif defined(RT_OS_LINUX)
+#elif defined(RT_OS_FREEBSD) || defined(RT_OS_LINUX)
     /* signal to the thread that it is supposed to exit */
     pState->bTerminate = true;
     /* wait for it to terminate */
@@ -3216,7 +3216,7 @@ static DECLCALLBACK(int) vmsvga3dBackGenerateMipmaps(P
 }
 
 
-#ifdef RT_OS_LINUX
+#if defined(RT_OS_FREEBSD) || defined(RT_OS_LINUX)
 /**
  * X11 event handling thread.
  *
@@ -3246,7 +3246,7 @@ static DECLCALLBACK(int) vmsvga3dXEventThread(RTTHREAD
     }
     return VINF_SUCCESS;
 }
-#endif // RT_OS_LINUX
+#endif // RT_OS_FREEBSD || RT_OS_LINUX
 
 
 /**
@@ -3484,7 +3484,7 @@ int vmsvga3dContextDefineOgl(PVGASTATECC pThisCC, uint
     return VINF_SUCCESS;
 }
 
-#if defined(RT_OS_LINUX)
+#if defined(RT_OS_FREEBSD) || defined(RT_OS_LINUX)
 /*
  * HW accelerated graphics output.
  */
@@ -3976,7 +3976,7 @@ static DECLCALLBACK(int) vmsvga3dBackSurfaceBlitToScre
     return VINF_SUCCESS;
 }
 
-#else /* !RT_OS_LINUX */
+#else /* !RT_OS_FREEBSD && !RT_OS_LINUX */
 
 static DECLCALLBACK(int) vmsvga3dBackDefineScreen(PVGASTATE pThis, PVGASTATECC pThisCC, VMSVGASCREENOBJECT *pScreen)
 {
@@ -4096,7 +4096,7 @@ static int vmsvga3dContextDestroyOgl(PVGASTATECC pThis
     AssertRC(rc);
 #elif defined(RT_OS_DARWIN)
     vmsvga3dCocoaDestroyViewAndContext(pContext->cocoaView, pContext->cocoaContext);
-#elif defined(RT_OS_LINUX)
+#elif defined(RT_OS_FREEBSD) || defined(RT_OS_LINUX)
     glXMakeCurrent(pState->display, None, NULL);
     glXDestroyContext(pState->display, pContext->glxContext);
     XDestroyWindow(pState->display, pContext->window);
