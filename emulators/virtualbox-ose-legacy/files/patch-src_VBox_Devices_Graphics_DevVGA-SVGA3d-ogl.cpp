--- src/VBox/Devices/Graphics/DevVGA-SVGA3d-ogl.cpp.orig	2020-07-09 16:55:07 UTC
+++ src/VBox/Devices/Graphics/DevVGA-SVGA3d-ogl.cpp
@@ -1094,7 +1094,7 @@ int vmsvga3dTerminate(PVGASTATE pThis)
     RTSemEventDestroy(pState->WndRequestSem);
 #elif defined(RT_OS_DARWIN)
 
-#elif defined(RT_OS_LINUX)
+#elif defined(RT_OS_FREEBSD) || defined(RT_OS_LINUX)
     /* signal to the thread that it is supposed to exit */
     pState->bTerminate = true;
     /* wait for it to terminate */
@@ -3200,7 +3200,7 @@ int vmsvga3dCommandPresent(PVGASTATE pThis, uint32_t s
     return VINF_SUCCESS;
 }
 
-#ifdef RT_OS_LINUX
+#if defined(RT_OS_FREEBSD) || defined(RT_OS_LINUX)
 /**
  * X11 event handling thread.
  *
@@ -3230,7 +3230,7 @@ DECLCALLBACK(int) vmsvga3dXEventThread(RTTHREAD hThrea
     }
     return VINF_SUCCESS;
 }
-#endif // RT_OS_LINUX
+#endif // RT_OS_FREEBSD || RT_OS_LINUX
 
 
 /**
@@ -3590,7 +3590,7 @@ static int vmsvga3dContextDestroyOgl(PVGASTATE pThis, 
     AssertRC(rc);
 #elif defined(RT_OS_DARWIN)
     vmsvga3dCocoaDestroyViewAndContext(pContext->cocoaView, pContext->cocoaContext);
-#elif defined(RT_OS_LINUX)
+#elif defined(RT_OS_FREEBSD) || defined(RT_OS_LINUX)
     glXMakeCurrent(pState->display, None, NULL);
     glXDestroyContext(pState->display, pContext->glxContext);
     XDestroyWindow(pState->display, pContext->window);
@@ -3648,7 +3648,7 @@ static void vmsvga3dChangeModeOneContext(PVGASTATE pTh
     RT_NOREF(pState);
     vmsvga3dCocoaViewSetSize(pContext->cocoaView, pThis->svga.uWidth, pThis->svga.uHeight);
 
-#elif defined(RT_OS_LINUX)
+#elif defined(RT_OS_FREEBSD) || defined(RT_OS_LINUX)
     XWindowChanges wc;
     wc.width = pThis->svga.uWidth;
     wc.height = pThis->svga.uHeight;
