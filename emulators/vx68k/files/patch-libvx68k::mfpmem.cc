--- libvx68k/mfpmem.cc.orig	Sat Jun 30 20:53:36 2001
+++ libvx68k/mfpmem.cc	Wed Dec  1 18:24:18 2004
@@ -37,7 +37,7 @@
 using namespace std;
 
 uint16_type
-mfp_memory::get_16(uint32_type address, function_code fc) const
+mfp_memory::get_16(uint32_type address, function_code fc) const throw()
 {
 #ifdef DL
   DL("class mfp_memory: get_16: fc=%d address=0x%08lx\n",
@@ -51,7 +51,7 @@
 }
 
 int
-mfp_memory::get_8(uint32_type address, function_code fc) const
+mfp_memory::get_8(uint32_type address, function_code fc) const throw()
 {
 #ifdef DL
   DL("class mfp_memory: get_8: fc=%d address=0x%08lx\n",
@@ -67,7 +67,7 @@
 }
 
 void
-mfp_memory::put_16(uint32_type address, uint16_type value, function_code fc)
+mfp_memory::put_16(uint32_type address, uint16_type value, function_code fc) throw()
 {
 #ifdef DL
   DL("class opm_memory: put_16: fc=%d address=0x%08lx value=0x%04x\n",
@@ -80,7 +80,7 @@
 }
 
 void
-mfp_memory::put_8(uint32_type address, int value, function_code fc)
+mfp_memory::put_8(uint32_type address, int value, function_code fc) throw()
 {
 #ifdef DL
   DL("class opm_memory: put_8: fc=%d address=0x%08lx value=0x%02x\n",
