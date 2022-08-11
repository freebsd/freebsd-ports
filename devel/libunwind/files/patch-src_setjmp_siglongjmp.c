--- src/setjmp/siglongjmp.c.orig	2020-11-10 16:14:18 UTC
+++ src/setjmp/siglongjmp.c
@@ -108,7 +108,7 @@ siglongjmp (sigjmp_buf env, int val)
                     && unw_set_reg (&c, UNW_REG_EH + 3, wp[JB_MASK + 1]) < 0))
               abort ();
 #elif defined(__FreeBSD__)
-          if (unw_set_reg (&c, UNW_REG_EH + 2, &wp[JB_MASK]) < 0)
+          if (unw_set_reg (&c, UNW_REG_EH + 2, wp[JB_MASK]) < 0)
               abort();
 #else
 #error Port me
