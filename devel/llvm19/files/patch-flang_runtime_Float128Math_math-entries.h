--- flang/runtime/Float128Math/math-entries.h.orig
+++ flang/runtime/Float128Math/math-entries.h
@@ -131,9 +131,11 @@
 DEFINE_SIMPLE_ALIAS(Ilogb, ilogbq)
 DEFINE_SIMPLE_ALIAS(Isinf, isinfq)
 DEFINE_SIMPLE_ALIAS(Isnan, isnanq)
+#ifndef __aarch64__
 DEFINE_SIMPLE_ALIAS(J0, j0q)
 DEFINE_SIMPLE_ALIAS(J1, j1q)
 DEFINE_SIMPLE_ALIAS(Jn, jnq)
+#endif
 DEFINE_SIMPLE_ALIAS(Ldexp, ldexpq)
 DEFINE_SIMPLE_ALIAS(Lgamma, lgammaq)
 DEFINE_SIMPLE_ALIAS(Llround, llroundq)
@@ -150,9 +152,11 @@
 DEFINE_SIMPLE_ALIAS(Tanh, tanhq)
 DEFINE_SIMPLE_ALIAS(Tgamma, tgammaq)
 DEFINE_SIMPLE_ALIAS(Trunc, truncq)
+#ifdef __aarch64__
 DEFINE_SIMPLE_ALIAS(Y0, y0q)
 DEFINE_SIMPLE_ALIAS(Y1, y1q)
 DEFINE_SIMPLE_ALIAS(Yn, ynq)
+#endif
 
 // Use cmath INFINITY/NAN definition. Rely on C implicit conversions.
 #define F128_RT_INFINITY (INFINITY)
@@ -185,9 +189,11 @@
 DEFINE_SIMPLE_ALIAS(Ilogb, std::ilogb)
 DEFINE_SIMPLE_ALIAS(Isinf, std::isinf)
 DEFINE_SIMPLE_ALIAS(Isnan, std::isnan)
+#ifndef __aarch64__
 DEFINE_SIMPLE_ALIAS(J0, j0l)
 DEFINE_SIMPLE_ALIAS(J1, j1l)
 DEFINE_SIMPLE_ALIAS(Jn, jnl)
+#endif
 DEFINE_SIMPLE_ALIAS(Ldexp, std::ldexp)
 DEFINE_SIMPLE_ALIAS(Lgamma, std::lgamma)
 DEFINE_SIMPLE_ALIAS(Llround, std::llround)
@@ -204,9 +210,11 @@
 DEFINE_SIMPLE_ALIAS(Tanh, std::tanh)
 DEFINE_SIMPLE_ALIAS(Tgamma, std::tgamma)
 DEFINE_SIMPLE_ALIAS(Trunc, std::trunc)
+#ifndef __aarch64__
 DEFINE_SIMPLE_ALIAS(Y0, y0l)
 DEFINE_SIMPLE_ALIAS(Y1, y1l)
 DEFINE_SIMPLE_ALIAS(Yn, ynl)
+#endif
 
 // Use numeric_limits to produce infinity of the right type.
 #define F128_RT_INFINITY \
