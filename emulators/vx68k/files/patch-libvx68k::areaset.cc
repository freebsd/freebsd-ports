--- libvx68k/areaset.cc.orig	Sun Jul  1 21:12:40 2001
+++ libvx68k/areaset.cc	Wed Dec  1 18:24:18 2004
@@ -37,7 +37,7 @@
 using namespace std;
 
 uint16_type
-area_set::get_16(uint32_type address, function_code fc) const
+area_set::get_16(uint32_type address, function_code fc) const throw()
 {
 #ifdef L
   L("class area_set: get_16 fc=%d address=%#010x\n", fc, address);
@@ -46,7 +46,7 @@
 }
 
 int
-area_set::get_8(uint32_type address, function_code fc) const
+area_set::get_8(uint32_type address, function_code fc) const throw()
 {
 #ifdef L
   L("class area_set: get_8 fc=%d address=%#010x\n", fc, address);
@@ -55,7 +55,7 @@
 }
 
 void
-area_set::put_8(uint32_type address, int value, function_code fc)
+area_set::put_8(uint32_type address, int value, function_code fc) throw()
 {
   address &= 0xffffffffu;
   value &= 0xffu;
@@ -84,7 +84,7 @@
 }
 
 void
-area_set::put_16(uint32_type address, uint16_type value, function_code fc)
+area_set::put_16(uint32_type address, uint16_type value, function_code fc) throw()
 {
   this->put_8(address / 2 * 2 + 1, value, fc);
 }
