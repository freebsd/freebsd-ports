--- libvx68k/opmmem.cc.orig	Sun Jul  1 21:24:37 2001
+++ libvx68k/opmmem.cc	Wed Dec  1 18:24:18 2004
@@ -127,7 +127,7 @@
 }
 
 int
-opm_memory::get_8(uint32_type address, function_code fc) const
+opm_memory::get_8(uint32_type address, function_code fc) const throw()
 {
   address &= 0xffffffffu;
 #ifdef DL
@@ -153,7 +153,7 @@
 }
 
 uint16_type
-opm_memory::get_16(uint32_type address, function_code fc) const
+opm_memory::get_16(uint32_type address, function_code fc) const throw()
 {
 #ifdef DL
   DL("class opm_memory: get_16: fc=%d address=0x%08lx\n",
@@ -164,7 +164,7 @@
 }
 
 void
-opm_memory::put_8(uint32_type address, int value, function_code fc)
+opm_memory::put_8(uint32_type address, int value, function_code fc) throw()
 {
   address &= 0xffffffffu;
   value &= 0xffu;
@@ -194,7 +194,7 @@
 }
 
 void
-opm_memory::put_16(uint32_type address, uint16_type value, function_code fc)
+opm_memory::put_16(uint32_type address, uint16_type value, function_code fc) throw()
 {
   address &= 0xffffffffu;
   value &= 0xffffu;
