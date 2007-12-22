--- ../gcc/config/freebsd-spec.h.orig	2007-12-21 20:20:55.000000000 -0500
+++ ../gcc/config/freebsd-spec.h	2007-12-21 20:21:32.000000000 -0500
@@ -75,7 +75,9 @@
 #define FBSD_TARGET_OS_CPP_BUILTINS()					\
   do									\
     {									\
-	if (FBSD_MAJOR == 7)						\
+	if (FBSD_MAJOR == 8)						\
+	  builtin_define ("__FreeBSD__=8");			       	\
+	else if (FBSD_MAJOR == 7)					\
 	  builtin_define ("__FreeBSD__=7");			       	\
 	else if (FBSD_MAJOR == 6)					\
 	  builtin_define ("__FreeBSD__=6");			       	\
