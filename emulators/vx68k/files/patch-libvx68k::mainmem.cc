--- libvx68k/mainmem.cc.orig	Sun Jul  1 21:25:57 2001
+++ libvx68k/mainmem.cc	Wed Dec  1 18:24:18 2004
@@ -55,7 +55,7 @@
 }
 
 int
-main_memory::get_8(uint32_type address, function_code fc) const
+main_memory::get_8(uint32_type address, function_code fc) const throw()
 {
   if (address % 0x1000000U >= end)
     throw bus_error(address, READ | fc);
@@ -75,7 +75,7 @@
 }
 
 uint16_type
-main_memory::get_16(uint32_type address, function_code fc) const
+main_memory::get_16(uint32_type address, function_code fc) const throw()
 {
   assert((address & 1) == 0);
   if (address % 0x1000000U >= end)
@@ -89,7 +89,7 @@
 }
 
 uint32_type
-main_memory::get_32(uint32_type address, function_code fc) const
+main_memory::get_32(uint32_type address, function_code fc) const throw()
 {
   assert((address & 3) == 0);
   if (address % 0x1000000U >= end)
@@ -106,7 +106,7 @@
 }
 
 void
-main_memory::put_8(uint32_type address, int value, function_code fc)
+main_memory::put_8(uint32_type address, int value, function_code fc) throw()
 {
   value &= 0xff;
 
@@ -126,7 +126,7 @@
 }
 
 void
-main_memory::put_16(uint32_type address, uint16_type value, function_code fc)
+main_memory::put_16(uint32_type address, uint16_type value, function_code fc) throw()
 {
   assert((address & 1) == 0);
   value &= 0xffff;
@@ -140,7 +140,7 @@
 }
 
 void
-main_memory::put_32(uint32_type address, uint32_type value, function_code fc)
+main_memory::put_32(uint32_type address, uint32_type value, function_code fc) throw()
 {
   assert((address & 3) == 0);
   value &= 0xffffffffU;
