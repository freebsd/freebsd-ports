--- libvx68k/ppimem.cc.orig	Sat Jun 30 20:54:42 2001
+++ libvx68k/ppimem.cc	Wed Dec  1 18:24:18 2004
@@ -37,7 +37,7 @@
 using namespace std;
 
 uint16_type
-ppi_memory::get_16(uint32_type address, function_code fc) const
+ppi_memory::get_16(uint32_type address, function_code fc) const throw()
 {
 #ifdef DL
   DL("class ppi_memory: get_16: fc=%d address=0x%08lx\n", fc, address + 0UL);
@@ -47,7 +47,7 @@
 }
 
 int
-ppi_memory::get_8(uint32_type address, function_code fc) const
+ppi_memory::get_8(uint32_type address, function_code fc) const throw()
 {
   address &= 0xffffffffU;
 
@@ -65,7 +65,7 @@
 }
 
 void
-ppi_memory::put_16(uint32_type address, uint16_type value, function_code fc)
+ppi_memory::put_16(uint32_type address, uint16_type value, function_code fc) throw()
 {
 #ifdef DL
   DL("class ppi_memory: put_16: fc=%d address=0x%08lx value=0x%04x\n",
@@ -78,7 +78,7 @@
 }
 
 void
-ppi_memory::put_8(uint32_type address, int value, function_code fc)
+ppi_memory::put_8(uint32_type address, int value, function_code fc) throw()
 {
 #ifdef DL
   DL("class ppi_memory: put_8: fc=%d address=0x%08lx value=0x%02x\n",
