--- m4/optimizations.m4.orig	2008-09-10 01:46:12.000000000 +0200
+++ m4/optimizations.m4	2010-10-22 23:30:38.000000000 +0200
@@ -98,15 +98,15 @@
 
 if test x_$enable_altivec = x_yes ; then
   AC_DEFINE_UNQUOTED([USE_ALTIVEC],[1],
-    [Define to 1 if you want to use ALTIVEC optimizations])
+    [Define to 1 if you want to use ALTIVEC optimizations, disabled in this port])
 # put compiler specific flags here
-  if test x_$ac_cv_c_compiler_gnu = x_yes ; then
-    SAH_CHECK_CFLAG([-faltivec],[CFLAGS="-faltivec ${CFLAGS}"])
-    SAH_CHECK_CFLAG([-maltivec],[CFLAGS="-maltivec ${CFLAGS}"])
-    SAH_CHECK_CFLAG([-mtune=G5],[CFLAGS="-mtune=G5 ${CFLAGS}"])
-    SAH_CHECK_CFLAG([-mcpu=powerpc],[CFLAGS="-mcpu=powerpc ${CFLAGS}"])
-    SAH_CHECK_LDFLAG([-framework Accelerate],[LDFLAGS="${LDFLAGS} -framework Accelerate"])
-  fi
+#  if test x_$ac_cv_c_compiler_gnu = x_yes ; then
+#    SAH_CHECK_CFLAG([-faltivec],[CFLAGS="-faltivec ${CFLAGS}"])
+#    SAH_CHECK_CFLAG([-maltivec],[CFLAGS="-maltivec ${CFLAGS}"])
+#    SAH_CHECK_CFLAG([-mtune=G5],[CFLAGS="-mtune=G5 ${CFLAGS}"])
+#    SAH_CHECK_CFLAG([-mcpu=powerpc],[CFLAGS="-mcpu=powerpc ${CFLAGS}"])
+#    SAH_CHECK_LDFLAG([-framework Accelerate],[LDFLAGS="${LDFLAGS} -framework Accelerate"])
+#  fi
 fi
 
 fi
