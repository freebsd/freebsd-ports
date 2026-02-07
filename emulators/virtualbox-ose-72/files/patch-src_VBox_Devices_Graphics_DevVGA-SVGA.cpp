--- src/VBox/Devices/Graphics/DevVGA-SVGA.cpp.orig	2025-08-13 19:47:43 UTC
+++ src/VBox/Devices/Graphics/DevVGA-SVGA.cpp
@@ -178,7 +178,7 @@
 # ifdef RT_OS_DARWIN
 #  include "DevVGA-SVGA3d-cocoa.h"
 # endif
-# ifdef RT_OS_LINUX
+# if defined(RT_OS_FREEBSD) || defined(RT_OS_LINUX)
 #  ifdef IN_RING3
 #   include "DevVGA-SVGA3d-glLdr.h"
 #  endif
@@ -7949,7 +7949,7 @@ static void vmsvgaR3PowerOnDevice(PPDMDEVINS pDevIns, 
     }
 # endif
 
-# if defined(VBOX_WITH_VMSVGA3D) && defined(RT_OS_LINUX)
+# if defined(VBOX_WITH_VMSVGA3D) && (defined(RT_OS_FREEBSD) || defined(RT_OS_LINUX))
     if (pThis->svga.f3DEnabled)
     {
         /* The FIFO thread may use X API for accelerated screen output. */
