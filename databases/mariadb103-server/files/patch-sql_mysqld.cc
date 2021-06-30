--- sql/mysqld.cc.orig	2021-05-05 15:26:23 UTC
+++ sql/mysqld.cc
@@ -206,7 +206,7 @@ typedef fp_except fp_except_t;
 
 inline void setup_fpu()
 {
-#if defined(__FreeBSD__) && defined(HAVE_IEEEFP_H) && !defined(HAVE_FEDISABLEEXCEPT)
+#if defined(__FreeBSD__) && defined(HAVE_IEEEFP_H) && !defined(HAVE_FEDISABLEEXCEPT) && defined(FP_X_INV)
   /* We can't handle floating point exceptions with threads, so disable
      this on freebsd
      Don't fall for overflow, underflow,divide-by-zero or loss of precision.
@@ -219,7 +219,7 @@ inline void setup_fpu()
   fpsetmask(~(FP_X_INV |             FP_X_OFL | FP_X_UFL | FP_X_DZ |
               FP_X_IMP));
 #endif /* FP_X_DNML */
-#endif /* __FreeBSD__ && HAVE_IEEEFP_H && !HAVE_FEDISABLEEXCEPT */
+#endif /* __FreeBSD__ && HAVE_IEEEFP_H && !HAVE_FEDISABLEEXCEPT && defined(FP_X_INV) */
 
 #ifdef HAVE_FEDISABLEEXCEPT
   fedisableexcept(FE_ALL_EXCEPT);
@@ -5033,8 +5033,9 @@ static void init_ssl()
       while ((err= ERR_get_error()))
         sql_print_warning("SSL error: %s", ERR_error_string(err, NULL));
     }
-    else
+    else {
       ERR_remove_state(0);
+    }
   }
   else
   {
