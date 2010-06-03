--- src/gfx/generic/generic.c
+++ src/gfx/generic/generic.c
@@ -63,6 +63,8 @@
 #include "duffs_device.h"
 
 
+typedef unsigned long ulong;
+
 /* lookup tables for 2/3bit to 8bit color conversion */
 static const u8 lookup3to8[] = { 0x00, 0x24, 0x49, 0x6d, 0x92, 0xb6, 0xdb, 0xff};
 static const u8 lookup2to8[] = { 0x00, 0x55, 0xaa, 0xff};
