--- gts/rounding.h.orig	2020-12-31 20:18:44 UTC
+++ gts/rounding.h
@@ -42,11 +42,11 @@
 #    define FPU_RESTORE
 #  endif /* not FPU_EXTENDED */
 #else /* not HAVE_FPU_CONTROL_H */
-#  ifdef __FreeBSD__
+#  ifdef HAVE_FROATINGPOINT_H
 #    include <floatingpoint.h>
 #    define FPU_ROUND_DOUBLE  (fpsetprec(FP_PD))
 #    define FPU_RESTORE       (fpsetprec(FP_PE))
-#  else /* not __FreeBSD__ */
+#  else /* not HAVE_FROATINGPOINT_H */
 #    ifdef WIN32
 #      ifdef _MSC_VER
 #        include <float.h>
