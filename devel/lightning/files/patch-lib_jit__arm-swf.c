--- lib/jit_arm-swf.c.orig	2022-11-30 10:43:45 UTC
+++ lib/jit_arm-swf.c
@@ -402,7 +402,7 @@ static void _swf_vaarg_d(jit_state_t*, jit_int32_t, ji
 	    BICI(rt, rn, encode_arm_immediate(im));			\
     } while (0)

-#if !defined(__GNUC__)
+#if !defined(__GNUC__) || defined(__llvm__)
 float __addsf3(float u, float v)
 {
     return (u + v);
@@ -414,6 +414,8 @@ __adddf3(double u, double v)
     return (u + v);
 }

+#endif
+#if !defined(__GNUC__)
 float
 __aeabi_fsub(float u, float v)
 {
