--- libvx68k/sysportmem.cc.orig	Sat Jun 30 20:53:40 2001
+++ libvx68k/sysportmem.cc	Wed Dec  1 18:24:18 2004
@@ -37,7 +37,7 @@
 using namespace std;
 
 uint16_type
-system_ports_memory::get_16(uint32_type address, function_code fc) const
+system_ports_memory::get_16(uint32_type address, function_code fc) const throw()
 {
 #ifdef DL
   DL("class system_ports_memory: get_16: fc=%d address=0x%08lx\n",
@@ -52,7 +52,7 @@
 }
 
 int
-system_ports_memory::get_8(uint32_type address, function_code fc) const
+system_ports_memory::get_8(uint32_type address, function_code fc) const throw()
 {
 #ifdef DL
   DL("class system_ports_memory: get_8: fc=%d address=0x%08lx\n",
@@ -68,7 +68,7 @@
 
 void
 system_ports_memory::put_16(uint32_type address, uint16_type value,
-			    function_code fc)
+			    function_code fc) throw()
 {
 #ifdef DL
   DL("class opm_memory: put_16: fc=%d address=0x%08lx value=0x%04x\n",
@@ -82,7 +82,7 @@
 }
 
 void
-system_ports_memory::put_8(uint32_type address, int value, function_code fc)
+system_ports_memory::put_8(uint32_type address, int value, function_code fc) throw()
 {
 #ifdef DL
   DL("class opm_memory: put_8: fc=%d address=0x%08lx value=0x%02x\n",
