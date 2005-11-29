--- gcc/config/freebsd-spec.h.orig	Sun May  1 21:04:41 2005
+++ gcc/config/freebsd-spec.h	Wed Nov 23 23:45:24 2005
@@ -51,7 +51,9 @@
 #define FBSD_TARGET_OS_CPP_BUILTINS()					\
   do									\
     {									\
-	if (FBSD_MAJOR == 6)						\
+	if (FBSD_MAJOR == 7)						\
+	  builtin_define ("__FreeBSD__=7");			       	\
+	else if (FBSD_MAJOR == 6)					\
 	  builtin_define ("__FreeBSD__=6");			       	\
 	else if (FBSD_MAJOR == 5)	       				\
 	  builtin_define ("__FreeBSD__=5");			       	\
