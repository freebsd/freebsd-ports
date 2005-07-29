--- src/nv3.c.orig	Tue Jul 26 22:09:54 2005
+++ src/nv3.c	Tue Jul 26 22:08:17 2005
@@ -579,7 +579,7 @@
 
 #define MapDevice(device,base) \
   nv##device##Port=(unsigned*)(mmap(0, \
-     	DEVICE_SIZE(device),PROT_WRITE,MAP_SHARED,__svgalib_mem_fd,\
+     	DEVICE_SIZE(device),(PROT_WRITE|PROT_READ),MAP_SHARED,__svgalib_mem_fd,\
         (MMIOBASE)+DEVICE_BASE(device)))
 
 /* Initialize chipset (called after detection) */
@@ -616,6 +616,7 @@
           case 0x29: case 0x2A: case 0x2B: case 0x2C: case 0x2D: case 0x2E: case 0x2F:
           case 0xA0:
           case 0x28: nv3_chiptype=RivaTNT; break;
+          case 0x185:
           case 0x150: case 0x151: case 0x152: case 0x153:
           case 0x110: case 0x111: case 0x113:
           case 0x101: case 0x103:
