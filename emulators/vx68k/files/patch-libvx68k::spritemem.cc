--- libvx68k/spritemem.cc.orig	Sat Jun 30 20:54:48 2001
+++ libvx68k/spritemem.cc	Wed Dec  1 18:24:18 2004
@@ -38,7 +38,7 @@
 using namespace std;
 
 uint16_type
-sprites_memory::get_16(uint32_type address, function_code fc) const
+sprites_memory::get_16(uint32_type address, function_code fc) const throw()
 {
 #ifdef L
   L("class sprites_memory: get_16: fc=%d address=%#010lx\n",
@@ -49,7 +49,7 @@
 }
 
 int
-sprites_memory::get_8(uint32_type address, function_code fc) const
+sprites_memory::get_8(uint32_type address, function_code fc) const throw()
 {
 #ifdef L
   L("class sprites_memory: get_8: fc=%d address=%#010lx\n",
@@ -65,7 +65,7 @@
 
 void
 sprites_memory::put_16(uint32_type address, uint16_type value,
-		       function_code fc)
+		       function_code fc) throw()
 {
 #ifdef L
   L("class sprites_memory: put_16: fc=%d address=%#010lx value=%#06x\n",
@@ -75,7 +75,7 @@
 }
 
 void
-sprites_memory::put_8(uint32_type address, int value, function_code fc)
+sprites_memory::put_8(uint32_type address, int value, function_code fc) throw()
 {
 #ifdef L
   L("class sprites_memory: put_8: fc=%d address=%#010lx value=%#04x\n",
