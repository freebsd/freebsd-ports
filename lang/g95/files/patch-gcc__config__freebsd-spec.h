--- ../gcc-4.0.3/gcc/config/freebsd-spec.h.orig	2005-07-20 13:12:58.000000000 +0200
+++ ../gcc-4.0.3/gcc/config/freebsd-spec.h	2012-06-20 15:57:35.000000000 +0200
@@ -51,11 +51,13 @@
 #define FBSD_TARGET_OS_CPP_BUILTINS()					\
   do									\
     {									\
-	if (FBSD_MAJOR == 9)						\
+	if (FBSD_MAJOR == 10)						\
+	  builtin_define ("__FreeBSD__=10");			       	\
+	else if (FBSD_MAJOR == 9)						\
 	  builtin_define ("__FreeBSD__=9");			       	\
 	else if (FBSD_MAJOR == 8)					\
 	  builtin_define ("__FreeBSD__=8");			       	\
-	if (FBSD_MAJOR == 7)						\
+	else if (FBSD_MAJOR == 7)					\
 	  builtin_define ("__FreeBSD__=7");			       	\
 	else if (FBSD_MAJOR == 6)					\
 	  builtin_define ("__FreeBSD__=6");			       	\
