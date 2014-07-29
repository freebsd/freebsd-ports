--- src/rounding.h.orig	Mon Jun 17 12:05:45 2002
+++ src/rounding.h	Wed Sep 24 12:57:41 2003
@@ -28,11 +28,11 @@
                              _FPU_SETCW(fpu_round_double); }
 #  define FPU_RESTORE       {_FPU_SETCW(fpu_init);}
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
