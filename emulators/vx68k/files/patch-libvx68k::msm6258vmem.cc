--- libvx68k/msm6258vmem.cc.orig	Sat Jun 30 20:53:54 2001
+++ libvx68k/msm6258vmem.cc	Wed Dec  1 18:24:18 2004
@@ -48,7 +48,7 @@
 }
 
 int
-msm6258v_memory::get_8(uint32_type address, function_code fc) const
+msm6258v_memory::get_8(uint32_type address, function_code fc) const throw()
 {
   address &= 0xffffffff;
 #ifdef LG
@@ -64,7 +64,7 @@
 }
 
 uint16_type
-msm6258v_memory::get_16(uint32_type address, function_code fc) const
+msm6258v_memory::get_16(uint32_type address, function_code fc) const throw()
 {
   address &= 0xffffffff & ~1;
 #ifdef LG
@@ -81,7 +81,7 @@
 }
 
 void
-msm6258v_memory::put_8(uint32_type address, int value, function_code fc)
+msm6258v_memory::put_8(uint32_type address, int value, function_code fc) throw()
 {
   address &= 0xffffffff;
   value &= 0xff;
@@ -98,7 +98,7 @@
 
 void
 msm6258v_memory::put_16(uint32_type address, uint16_type value,
-			function_code fc)
+			function_code fc) throw()
 {
   address &= 0xffffffff & ~1;
   value &= 0xff;
