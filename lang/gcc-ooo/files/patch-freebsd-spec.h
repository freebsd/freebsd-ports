--- gcc/config/freebsd-spec.h.orig	Wed Mar  3 07:34:55 2004
+++ gcc/config/freebsd-spec.h	Sat Aug 13 18:47:14 2005
@@ -51,7 +51,9 @@
 #define FBSD_TARGET_OS_CPP_BUILTINS()					\
   do									\
     {									\
-	if (FBSD_MAJOR == 6)						\
+	if (FBSD_MAJOR == 7)						\
+	  builtin_define ("__FreeBSD__=7");			       	\
+	else if (FBSD_MAJOR == 6)	       				\
 	  builtin_define ("__FreeBSD__=6");			       	\
 	else if (FBSD_MAJOR == 5)	       				\
 	  builtin_define ("__FreeBSD__=5");			       	\
@@ -130,11 +132,19 @@
   }"
 #else
 #if FBSD_MAJOR >= 5
+#if __FreeBSD_version < 502102 /* upto FreeBSD 5.2.1 */
 #define FBSD_LIB_SPEC "							\
   %{!shared:								\
     %{!pg: %{pthread:-lc_r} -lc}					\
     %{pg:  %{pthread:-lc_r_p} -lc_p}					\
   }"
+#else
+#define FBSD_LIB_SPEC "							\
+  %{!shared:								\
+    %{!pg: %{pthread:-lpthread} -lc}					\
+    %{pg:  %{pthread:-lpthread_p} -lc_p}					\
+  }"
+#endif	/* deal with FreeBSD 5.0 - 5.2.1 */
 #else
 #define FBSD_LIB_SPEC "							\
   %{!shared:								\
