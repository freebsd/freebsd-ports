--- ../gcc-4.0.3/gcc/config/freebsd-spec.h.orig	2007-12-26 10:31:59.000000000 -0500
+++ ../gcc-4.0.3/gcc/config/freebsd-spec.h	2007-12-26 10:32:21.000000000 -0500
@@ -55,7 +55,7 @@
 	  builtin_define ("__FreeBSD__=9");			       	\
 	else if (FBSD_MAJOR == 8)					\
 	  builtin_define ("__FreeBSD__=8");			       	\
-	if (FBSD_MAJOR == 7)						\
+	else if (FBSD_MAJOR == 7)					\
 	  builtin_define ("__FreeBSD__=7");			       	\
 	else if (FBSD_MAJOR == 6)					\
 	  builtin_define ("__FreeBSD__=6");			       	\
