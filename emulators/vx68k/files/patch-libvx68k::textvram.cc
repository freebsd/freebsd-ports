--- libvx68k/textvram.cc.orig	Sun Jul  1 21:24:21 2001
+++ libvx68k/textvram.cc	Wed Dec  1 18:24:18 2004
@@ -478,7 +478,7 @@
 }
 
 uint16_type
-text_video_memory::get_16(uint32_type address, function_code fc) const
+text_video_memory::get_16(uint32_type address, function_code fc) const throw()
 {
   if (fc != SUPER_DATA)
     throw bus_error(address, READ | fc);
@@ -490,7 +490,7 @@
 }
 
 int
-text_video_memory::get_8(uint32_type address, function_code fc) const
+text_video_memory::get_8(uint32_type address, function_code fc) const throw()
 {
   if (fc != SUPER_DATA)
     throw bus_error(address, READ | fc);
@@ -502,7 +502,7 @@
 
 void
 text_video_memory::put_16(uint32_type address, uint16_type value,
-			  function_code fc)
+			  function_code fc) throw()
 {
   if (fc != SUPER_DATA)
     throw bus_error(address, WRITE | fc);
@@ -520,7 +520,7 @@
 }
 
 void
-text_video_memory::put_8(uint32_type address, int value, function_code fc)
+text_video_memory::put_8(uint32_type address, int value, function_code fc) throw()
 {
   if (fc != SUPER_DATA)
     throw bus_error(address, WRITE | fc);
