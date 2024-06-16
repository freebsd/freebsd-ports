--- sql/mysqld.cc.orig	2021-06-15 10:16:51 UTC
+++ sql/mysqld.cc
@@ -205,7 +205,7 @@ typedef fp_except fp_except_t;
 
 inline void setup_fpu()
 {
-#if defined(__FreeBSD__) && defined(HAVE_IEEEFP_H) && !defined(HAVE_FEDISABLEEXCEPT)
+#if defined(__FreeBSD__) && defined(HAVE_IEEEFP_H) && !defined(HAVE_FEDISABLEEXCEPT) && defined(FP_X_INV)
   /* We can't handle floating point exceptions with threads, so disable
      this on freebsd
      Don't fall for overflow, underflow,divide-by-zero or loss of precision.
@@ -218,7 +218,7 @@ inline void setup_fpu()
   fpsetmask(~(FP_X_INV |             FP_X_OFL | FP_X_UFL | FP_X_DZ |
               FP_X_IMP));
 #endif /* FP_X_DNML */
-#endif /* __FreeBSD__ && HAVE_IEEEFP_H && !HAVE_FEDISABLEEXCEPT */
+#endif /* __FreeBSD__ && HAVE_IEEEFP_H && !HAVE_FEDISABLEEXCEPT && FP_X_INV */
 
 #ifdef HAVE_FEDISABLEEXCEPT
   fedisableexcept(FE_ALL_EXCEPT);
