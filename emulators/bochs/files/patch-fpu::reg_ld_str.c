--- fpu/reg_ld_str.c.orig	Thu Feb 12 07:28:52 2004
+++ fpu/reg_ld_str.c	Fri Aug 27 02:42:12 2004
@@ -315,7 +315,7 @@
 
 
 /* Get a short from user memory */
-int  BX_CPP_AttrRegparmN(1)
+int  BX_CPP_AttrRegparmN(2)
 FPU_load_int16(bx_address _s, FPU_REG *loaded_data)
 {
   s16 s, negative;
