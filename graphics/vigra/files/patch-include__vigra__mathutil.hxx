--- include/vigra/mathutil.hxx.orig	2011-09-20 18:38:36.000000000 +0000
+++ include/vigra/mathutil.hxx
@@ -149,7 +149,7 @@ VIGRA_DEFINE_UNSIGNED_ABS(unsigned long 
 VIGRA_DEFINE_MISSING_ABS(signed char)
 VIGRA_DEFINE_MISSING_ABS(signed short)
 
-#if defined(_MSC_VER) && _MSC_VER < 1600
+#if defined(_MSC_VER) && _MSC_VER < 1600 || defined(__GNUC__) && (__GNUC__ < 4 || __GNUC__ == 4 && __GNUC_MINOR__ < 2) || defined(__clang__)
 VIGRA_DEFINE_MISSING_ABS(signed long long)
 #endif
 
@@ -553,7 +553,12 @@ VIGRA_DEFINE_NORM(int)
 VIGRA_DEFINE_NORM(unsigned int)
 VIGRA_DEFINE_NORM(long)
 VIGRA_DEFINE_NORM(unsigned long)
+#if defined(__FreeBSD__) || defined(__DragonFly__)
+inline NormTraits<long long>::SquaredNormType squaredNorm(long long t) { return sq((long int) t); }
+inline NormTraits<long long>::NormType norm(long long t) { return abs((long int) t); }
+#else
 VIGRA_DEFINE_NORM(long long)
+#endif
 VIGRA_DEFINE_NORM(unsigned long long)
 VIGRA_DEFINE_NORM(float)
 VIGRA_DEFINE_NORM(double)
