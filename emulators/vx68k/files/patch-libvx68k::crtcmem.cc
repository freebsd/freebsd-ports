--- libvx68k/crtcmem.cc.orig	Sat Jun 30 20:53:13 2001
+++ libvx68k/crtcmem.cc	Wed Dec  1 18:24:18 2004
@@ -76,7 +76,7 @@
 }
 
 uint16_type
-crtc_memory::get_16(uint32_type address, function_code fc) const
+crtc_memory::get_16(uint32_type address, function_code fc) const throw()
 {
 #ifdef DL
   DL("class crtc_memory: get_16: fc=%d address=0x%08lx\n", fc, address + 0UL);
@@ -92,7 +92,7 @@
 }
 
 int
-crtc_memory::get_8(uint32_type address, function_code fc) const
+crtc_memory::get_8(uint32_type address, function_code fc) const throw()
 {
 #ifdef DL
   DL("class crtc_memory: get_8: fc=%d address=0x%08lx\n", fc, address + 0UL);
@@ -106,7 +106,7 @@
 }
 
 void
-crtc_memory::put_16(uint32_type address, uint16_type value, function_code fc)
+crtc_memory::put_16(uint32_type address, uint16_type value, function_code fc) throw()
 {
 #ifdef DL
   DL("class crtc_memory: put_16: fc=%d address=0x%08lx value=0x%04x\n",
@@ -119,7 +119,7 @@
 }
 
 void
-crtc_memory::put_8(uint32_type address, int value, function_code fc)
+crtc_memory::put_8(uint32_type address, int value, function_code fc) throw()
 {
 #ifdef DL
   DL("class crtc_memory: put_8: fc=%d address=0x%08lx value=0x%02x\n",
