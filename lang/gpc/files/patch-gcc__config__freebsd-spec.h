--- ./gcc/config/freebsd-spec.h.orig	2005-05-01 21:52:41.000000000 +0000
+++ ./gcc/config/freebsd-spec.h	2011-01-04 11:36:10.000000000 +0000
@@ -51,7 +51,13 @@
 #define FBSD_TARGET_OS_CPP_BUILTINS()					\
   do									\
     {									\
-	if (FBSD_MAJOR == 6)						\
+	if (FBSD_MAJOR == 9)						\
+	  builtin_define ("__FreeBSD__=9");			       	\
+	else if (FBSD_MAJOR == 8)					\
+	  builtin_define ("__FreeBSD__=8");			       	\
+	else if (FBSD_MAJOR == 7)					\
+	  builtin_define ("__FreeBSD__=7");			       	\
+	else if (FBSD_MAJOR == 6)					\
 	  builtin_define ("__FreeBSD__=6");			       	\
 	else if (FBSD_MAJOR == 5)	       				\
 	  builtin_define ("__FreeBSD__=5");			       	\
