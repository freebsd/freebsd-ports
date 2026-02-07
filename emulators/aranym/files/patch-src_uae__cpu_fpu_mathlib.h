- https://github.com/aranym/aranym/issues/78

--- src/uae_cpu/fpu/mathlib.h.orig	2021-03-04 01:34:57 UTC
+++ src/uae_cpu/fpu/mathlib.h
@@ -756,7 +756,11 @@ PRIVATE inline uae_u32 FFPU get_quotient_sign(fpu_regi
 # define fp_pow		pow
 #endif
 #ifndef fp_pow10
-# define fp_pow10	pow10
+# if !defined(__FreeBSD__)
+#  define fp_pow10	pow10
+# else
+#  define fp_pow10(x)	pow(10,x)
+# endif
 #endif
 #ifndef fp_pow2
 # ifdef HAVE_POW2
