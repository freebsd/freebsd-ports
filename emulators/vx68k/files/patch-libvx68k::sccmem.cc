--- libvx68k/sccmem.cc.orig	Sat Jun 30 20:54:28 2001
+++ libvx68k/sccmem.cc	Wed Dec  1 18:24:18 2004
@@ -310,7 +310,7 @@
 }
 
 uint16_type
-scc_memory::get_16(uint32_type address, function_code fc) const
+scc_memory::get_16(uint32_type address, function_code fc) const throw()
 {
 #ifdef DL
   DL("class scc_memory: get_16: fc=%d address=0x%08lx\n", fc, address + 0UL);
@@ -322,7 +322,7 @@
 }
 
 int
-scc_memory::get_8(uint32_type address, function_code fc) const
+scc_memory::get_8(uint32_type address, function_code fc) const throw()
 {
 #ifdef DL
   DL("class scc_memory: get_8: fc=%d address=0x%08lx\n", fc, address + 0UL);
@@ -338,7 +338,7 @@
 }
 
 void
-scc_memory::put_16(uint32_type address, uint16_type value, function_code fc)
+scc_memory::put_16(uint32_type address, uint16_type value, function_code fc) throw()
 {
 #ifdef DL
   DL("class scc_memory: put_16: fc=%d address=0x%08lx value=0x%04x\n",
@@ -350,7 +350,7 @@
 }
 
 void
-scc_memory::put_8(uint32_type address, int value, function_code fc)
+scc_memory::put_8(uint32_type address, int value, function_code fc) throw()
 {
 #ifdef DL
   DL("class scc_memory: put_8: fc=%d address=0x%08lx value=0x%02x\n",
