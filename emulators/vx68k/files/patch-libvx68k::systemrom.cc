--- libvx68k/systemrom.cc.orig	Sun Jul  1 21:24:54 2001
+++ libvx68k/systemrom.cc	Wed Dec  1 18:24:18 2004
@@ -45,7 +45,7 @@
 #endif
 
 uint16_type
-system_rom::get_16(uint32_type address, function_code fc) const
+system_rom::get_16(uint32_type address, function_code fc) const throw()
 {
 #ifdef DL
   DL("class system_rom: get_16: fc=%d address=0x%08lx\n",
@@ -68,7 +68,7 @@
 }
 
 int
-system_rom::get_8(uint32_type address, function_code fc) const
+system_rom::get_8(uint32_type address, function_code fc) const throw()
 {
 #ifdef DL
   DL("class system_rom: get_8: fc=%d address=0x%08lx\n",
@@ -86,7 +86,7 @@
 }
 
 void
-system_rom::put_16(uint32_type address, uint16_type value, function_code fc)
+system_rom::put_16(uint32_type address, uint16_type value, function_code fc) throw()
 {
 #ifdef DL
   DL("class system_rom: put_16: fc=%d address=0x%08lx value=0x%04x\n",
@@ -101,7 +101,7 @@
 }
 
 void
-system_rom::put_8(uint32_type address, int value, function_code fc)
+system_rom::put_8(uint32_type address, int value, function_code fc) throw()
 {
 #ifdef DL
   DL("class system_rom: put_8: fc=%d address=0x%08lx value=0x%02x\n",
