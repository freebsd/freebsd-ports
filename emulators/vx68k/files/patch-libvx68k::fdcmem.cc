--- libvx68k/fdcmem.cc.orig	Sat Jun 30 20:53:59 2001
+++ libvx68k/fdcmem.cc	Wed Dec  1 18:24:18 2004
@@ -49,7 +49,7 @@
 }
 
 int
-fdc_memory::get_8(uint32_type address, function_code fc) const
+fdc_memory::get_8(uint32_type address, function_code fc) const throw()
 {
   address &= 0xffffffff;
 #ifdef LG
@@ -66,7 +66,7 @@
 }
 
 uint16_type
-fdc_memory::get_16(uint32_type address, function_code fc) const
+fdc_memory::get_16(uint32_type address, function_code fc) const throw()
 {
   address &= 0xffffffff & ~1;
 #ifdef LG
@@ -82,7 +82,7 @@
 }
 
 void
-fdc_memory::put_8(uint32_type address, int value, function_code fc)
+fdc_memory::put_8(uint32_type address, int value, function_code fc) throw()
 {
   address &= 0xffffffff;
   value &= 0xff;
@@ -98,7 +98,7 @@
 }
 
 void
-fdc_memory::put_16(uint32_type address, uint16_type value, function_code fc)
+fdc_memory::put_16(uint32_type address, uint16_type value, function_code fc) throw()
 {
   address &= 0xffffffff & ~1;
   value &= 0xff;
