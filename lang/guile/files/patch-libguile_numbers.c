--- libguile/numbers.c.orig	Thu Apr  3 23:52:25 2003
+++ libguile/numbers.c	Thu Apr  3 23:52:41 2003
@@ -89,8 +89,8 @@
 /* Return true if X is not infinite and is not a NaN
    Dirk:FIXME:: Since IS_INF is broken, this test does not work if x == 0
  */
-#ifndef isfinite
-#define isfinite(x) (!IS_INF (x) && (x) == (x))
+#ifndef xxx_isfinite
+#define xxx_isfinite(x) (!IS_INF (x) && (x) == (x))
 #endif
 
 
@@ -4071,7 +4071,7 @@
     if (SCM_FIXABLE (lu)) {
       return SCM_MAKINUM (lu);
 #ifdef SCM_BIGDIG
-    } else if (isfinite (u)) {
+    } else if (xxx_isfinite (u)) {
       return scm_dbl2big (u);
 #endif
     } else {
