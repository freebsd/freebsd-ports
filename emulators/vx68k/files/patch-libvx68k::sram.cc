--- libvx68k/sram.cc.orig	Sat Jun 30 20:54:57 2001
+++ libvx68k/sram.cc	Wed Dec  1 18:24:18 2004
@@ -48,7 +48,7 @@
 using namespace std;
 
 uint16_type
-sram::get_16(uint32_type address, function_code fc) const
+sram::get_16(uint32_type address, function_code fc) const throw()
 {
 #ifdef L
   L("class sram: get_16 fc=%d address=%#010x\n", fc, address);
@@ -60,7 +60,7 @@
 }
 
 int
-sram::get_8(uint32_type address, function_code fc) const
+sram::get_8(uint32_type address, function_code fc) const throw()
 {
 #ifdef L
   L("class sram: get_8 fc=%d address=%#010x\n", fc, address);
@@ -71,7 +71,7 @@
 }
 
 void
-sram::put_16(uint32_type, uint16_type, function_code)
+sram::put_16(uint32_type, uint16_type, function_code) throw()
 {
 #ifdef L
   L("class sram: FIXME: `put_16' not implemented\n");
@@ -79,7 +79,7 @@
 }
 
 void
-sram::put_8(uint32_type, int, function_code)
+sram::put_8(uint32_type, int, function_code) throw()
 {
 #ifdef L
   L("class sram: FIXME: `put_8' not implemented\n");
