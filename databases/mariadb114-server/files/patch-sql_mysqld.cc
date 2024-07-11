--- sql/mysqld.cc.orig	2024-05-26 18:15:38 UTC
+++ sql/mysqld.cc
@@ -209,7 +209,7 @@ inline void setup_fpu()
 
 inline void setup_fpu()
 {
-#if defined(__FreeBSD__) && defined(HAVE_IEEEFP_H) && !defined(HAVE_FEDISABLEEXCEPT)
+#if defined(__FreeBSD__) && defined(HAVE_IEEEFP_H) && !defined(HAVE_FEDISABLEEXCEPT) && defined(FP_X_INV)
   /* We can't handle floating point exceptions with threads, so disable
      this on freebsd
      Don't fall for overflow, underflow,divide-by-zero or loss of precision.
@@ -222,7 +222,7 @@ inline void setup_fpu()
   fpsetmask(~(FP_X_INV |             FP_X_OFL | FP_X_UFL | FP_X_DZ |
               FP_X_IMP));
 #endif /* FP_X_DNML */
-#endif /* __FreeBSD__ && HAVE_IEEEFP_H && !HAVE_FEDISABLEEXCEPT */
+#endif /* __FreeBSD__ && HAVE_IEEEFP_H && !HAVE_FEDISABLEEXCEPT && FP_X_INV */
 
 #ifdef HAVE_FEDISABLEEXCEPT
   fedisableexcept(FE_ALL_EXCEPT);
