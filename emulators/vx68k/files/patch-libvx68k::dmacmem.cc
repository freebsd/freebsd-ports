--- libvx68k/dmacmem.cc.orig	Sat Jun 30 20:53:29 2001
+++ libvx68k/dmacmem.cc	Wed Dec  1 18:24:18 2004
@@ -103,7 +103,7 @@
 }
 
 uint16_type
-dmac_memory::get_16(uint32_type address, function_code fc) const
+dmac_memory::get_16(uint32_type address, function_code fc) const throw()
 {
 #ifdef DL
   DL("class dmac_memory: get_16: fc=%d address=0x%08x\n", fc, address + 0UL);
@@ -115,7 +115,7 @@
 }
 
 int
-dmac_memory::get_8(uint32_type address, function_code fc) const
+dmac_memory::get_8(uint32_type address, function_code fc) const throw()
 {
 #ifdef DL
   DL("class dmac_memory: get_8: fc=%d address=0x%08x\n", fc, address + 0UL);
@@ -127,7 +127,7 @@
 }
 
 void
-dmac_memory::put_16(uint32_type address, uint16_type value, function_code fc)
+dmac_memory::put_16(uint32_type address, uint16_type value, function_code fc) throw()
 {
 #ifdef DL
   DL("class dmac_memory: put_16: fc=%d address=0x%08x value=0x%04x\n",
@@ -139,7 +139,7 @@
 }
 
 void
-dmac_memory::put_8(uint32_type address, int value, function_code fc)
+dmac_memory::put_8(uint32_type address, int value, function_code fc) throw()
 {
 #ifdef DL
   DL("class dmac_memory: put_8: fc=%d address=0x%08x value=0x%02x\n",
