--- libvx68k/fontrom.cc.orig	Sat Jun 30 20:55:03 2001
+++ libvx68k/fontrom.cc	Wed Dec  1 18:24:18 2004
@@ -322,7 +322,7 @@
 }
 
 uint16_type
-font_rom::get_16(uint32_type address, function_code fc) const
+font_rom::get_16(uint32_type address, function_code fc) const throw()
 {
 #ifdef DL
   DL("class font_rom: get_16: fc=%d address=0x%08lx\n", fc, address + 0UL);
@@ -340,7 +340,7 @@
 }
 
 int
-font_rom::get_8(uint32_type address, function_code fc) const
+font_rom::get_8(uint32_type address, function_code fc) const throw()
 {
 #ifdef DL
   DL("class font_rom: get_8: fc=%d address=0x%08lx\n", fc, address + 0UL);
@@ -356,7 +356,7 @@
 }
 
 void
-font_rom::put_16(uint32_type address, uint16_type value, function_code fc)
+font_rom::put_16(uint32_type address, uint16_type value, function_code fc) throw()
 {
 #ifdef DL
   DL("class font_rom: put_16: fc=%d address=0x%08lx value=0x%04x\n",
@@ -368,7 +368,7 @@
 }
 
 void
-font_rom::put_8(uint32_type address, int value, function_code fc)
+font_rom::put_8(uint32_type address, int value, function_code fc) throw()
 {
 #ifdef DL
   DL("class font_rom: put_8: fc=%d address=0x%08lx value=0x%02x\n",
