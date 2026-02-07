--- src/VBox/Devices/Graphics/DevVGA-SVGA.cpp.orig	2024-01-11 12:18:20 UTC
+++ src/VBox/Devices/Graphics/DevVGA-SVGA.cpp
@@ -169,7 +169,7 @@
 # ifdef RT_OS_DARWIN
 #  include "DevVGA-SVGA3d-cocoa.h"
 # endif
-# ifdef RT_OS_LINUX
+# if defined(RT_OS_FREEBSD) || defined(RT_OS_LINUX)
 #  ifdef IN_RING3
 #include "DevVGA-SVGA3d-glLdr.h"
 #  endif
@@ -3520,7 +3520,7 @@ static DECLCALLBACK(int) vmsvgaR3FifoLoop(PPDMDEVINS p
     PVMSVGAR3STATE  pSVGAState = pThisCC->svga.pSvgaR3State;
     int             rc;
 
-# if defined(VBOX_WITH_VMSVGA3D) && defined(RT_OS_LINUX)
+# if defined(VBOX_WITH_VMSVGA3D) && (defined(RT_OS_FREEBSD) || defined(RT_OS_LINUX))
     if (pThis->svga.f3DEnabled)
     {
         /* The FIFO thread may use X API for accelerated screen output. */
