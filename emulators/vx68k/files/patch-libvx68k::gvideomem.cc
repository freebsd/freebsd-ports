--- libvx68k/gvideomem.cc.orig	Sat Jun 30 20:52:35 2001
+++ libvx68k/gvideomem.cc	Wed Dec  1 18:24:18 2004
@@ -37,7 +37,7 @@
 using namespace std;
 
 uint16_type
-graphics_video_memory::get_16(uint32_type address, function_code fc) const
+graphics_video_memory::get_16(uint32_type address, function_code fc) const throw()
 {
 #ifdef DL
   DL("class graphics_video_memory: get_16: fc=%d address=0x%08lx\n",
@@ -51,7 +51,7 @@
 }
 
 int
-graphics_video_memory::get_8(uint32_type address, function_code fc) const
+graphics_video_memory::get_8(uint32_type address, function_code fc) const throw()
 {
 #ifdef DL
   DL("class graphics_video_memory: get_8: fc=%d address=0x%08lx\n",
@@ -66,7 +66,7 @@
 
 void
 graphics_video_memory::put_16(uint32_type address, uint16_type value,
-			      function_code fc)
+			      function_code fc) throw()
 {
 #ifdef DL
   DL("class graphics_video_memory: put_16: fc=%d address=0x%08lx value=0x%04x\n",
@@ -79,7 +79,7 @@
 }
 
 void
-graphics_video_memory::put_8(uint32_type address, int value, function_code fc)
+graphics_video_memory::put_8(uint32_type address, int value, function_code fc) throw()
 {
 #ifdef DL
   DL("class graphics_video_memory: put_8: fc=%d address=0x%08lx value=0x%02x\n",
