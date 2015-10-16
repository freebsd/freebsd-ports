--- stress-cpu.c.orig	2015-09-18 14:50:12 UTC
+++ stress-cpu.c
@@ -57,7 +58,6 @@
 #define	ccosl	ccos
 #define	csinl	csin
 #define cpow	pow
-#define powl	pow
 #endif
 
 /*
@@ -866,6 +866,7 @@ stress_cpu_fp(_Decimal128, decimal128, s
 /* Append floating point literal specifier to literal value */
 #define FP(val, ltype)	val ## ltype
 
+#if defined(__STDC_IEC_559_COMPLEX__)
 /*
  *  Generic complex stressor macro
  */
@@ -891,6 +892,7 @@ static void HOT OPTIMIZE3 stress_cpu_ ##
 stress_cpu_complex(complex float, f, complex_float, csinf, ccosf)
 stress_cpu_complex(complex double, , complex_double, csin, ccos)
 stress_cpu_complex(complex long double, l, complex_long_double, csinl, ccosl)
+#endif /* __STDC_IEC_559_COMPLEX__ */
 
 #define int_float_ops(_ftype, flt_a, flt_b, flt_c, flt_d,	\
 	_sin, _cos, int_a, int_b, _c1, _c2, _c3)		\
@@ -2058,9 +2060,11 @@ static stress_cpu_stressor_info_t cpu_me
 	{ "ackermann",		stress_cpu_ackermann },
 	{ "bitops",		stress_cpu_bitops },
 	{ "callfunc",		stress_cpu_callfunc },
+#if defined(__STDC_IEC_559_COMPLEX__)
 	{ "cdouble",		stress_cpu_complex_double },
 	{ "cfloat",		stress_cpu_complex_float },
 	{ "clongdouble",	stress_cpu_complex_long_double },
+#endif /* __STDC_IEC_559_COMPLEX__ */
 	{ "correlate",		stress_cpu_correlate },
 	{ "crc16",		stress_cpu_crc16 },
 #if defined(STRESS_FLOAT_DECIMAL)
