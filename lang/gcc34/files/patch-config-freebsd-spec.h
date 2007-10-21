--- gcc/config/freebsd-spec.h.orig	2005-07-19 17:08:48.000000000 -0400
+++ gcc/config/freebsd-spec.h	2007-10-17 15:13:55.000000000 -0400
@@ -55,7 +55,7 @@
 	  builtin_define ("__FreeBSD__=9");			       	\
 	else if (FBSD_MAJOR == 8)					\
 	  builtin_define ("__FreeBSD__=8");			       	\
-	if (FBSD_MAJOR == 7)						\
+	else if (FBSD_MAJOR == 7)						\
 	  builtin_define ("__FreeBSD__=7");			       	\
 	else if (FBSD_MAJOR == 6)					\
 	  builtin_define ("__FreeBSD__=6");			       	\
