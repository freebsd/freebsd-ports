--- libvx68k/palettemem.cc.orig	Sun Jul  1 21:22:36 2001
+++ libvx68k/palettemem.cc	Wed Dec  1 18:24:18 2004
@@ -91,7 +91,7 @@
 }
 
 uint16_type
-palettes_memory::get_16(uint32_type address, function_code fc) const
+palettes_memory::get_16(uint32_type address, function_code fc) const throw()
 {
   address &= 0xfffffffeu;
 #ifdef DL
@@ -133,7 +133,7 @@
 }
 
 int
-palettes_memory::get_8(uint32_type address, function_code fc) const
+palettes_memory::get_8(uint32_type address, function_code fc) const throw()
 {
   address &= 0xffffffffU;
 #ifdef DL
@@ -150,7 +150,7 @@
 
 void
 palettes_memory::put_16(uint32_type address, uint16_type value,
-			function_code fc)
+			function_code fc) throw()
 {
   address &= 0xfffffffeu;
   value &= 0xffffu;
@@ -197,7 +197,7 @@
 }
 
 void
-palettes_memory::put_8(uint32_type address, int value, function_code fc)
+palettes_memory::put_8(uint32_type address, int value, function_code fc) throw()
 {
   address &= 0xffffffffU;
   value &= 0xff;
