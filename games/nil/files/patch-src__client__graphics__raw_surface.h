--- ./src/client/graphics/raw_surface.h.orig	Thu Jan  6 08:08:23 2005
+++ ./src/client/graphics/raw_surface.h	Fri Jun 16 21:53:31 2006
@@ -28,7 +28,7 @@
 #define RAW_SURFACE_H
 
 #include "common/nil_files.h"
-#include <endian.h>
+#include <machine/endian.h>
 
 //! this must always become a 32bit integer
 typedef unsigned int Pixel;
@@ -36,7 +36,7 @@
 //! emulate ptc names
 typedef Pixel int32;
 
-#if __BYTE_ORDER == __LITTLE_ENDIAN
+#if BYTE_ORDER == LITTLE_ENDIAN
 
 //! pixelflags used in the map:
 #define PF_TYPE_BIT0 0x01000000
