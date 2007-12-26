--- gcc/config/freebsd-spec.h.orig	2004-03-02 17:34:55.000000000 -0500
+++ gcc/config/freebsd-spec.h	2007-12-26 09:17:49.000000000 -0500
@@ -51,7 +51,11 @@
 #define FBSD_TARGET_OS_CPP_BUILTINS()					\
   do									\
     {									\
-	if (FBSD_MAJOR == 6)						\
+	if (FBSD_MAJOR == 8)						\
+	  builtin_define ("__FreeBSD__=8");			       	\
+	else if (FBSD_MAJOR == 7)					\
+	  builtin_define ("__FreeBSD__=7");			       	\
+	else if (FBSD_MAJOR == 6)	       				\
 	  builtin_define ("__FreeBSD__=6");			       	\
 	else if (FBSD_MAJOR == 5)	       				\
 	  builtin_define ("__FreeBSD__=5");			       	\
@@ -130,6 +134,7 @@
   }"
 #else
 #if FBSD_MAJOR >= 5
+#if __FreeBSD_version < 502102 /* upto FreeBSD 5.2.1 */
 #define FBSD_LIB_SPEC "							\
   %{!shared:								\
     %{!pg: %{pthread:-lc_r} -lc}					\
@@ -138,6 +143,13 @@
 #else
 #define FBSD_LIB_SPEC "							\
   %{!shared:								\
+    %{!pg: %{pthread:-lpthread} -lc}					\
+    %{pg:  %{pthread:-lpthread_p} -lc_p}					\
+  }"
+#endif	/* deal with FreeBSD 5.0 - 5.2.1 */
+#else
+#define FBSD_LIB_SPEC "							\
+  %{!shared:								\
     %{!pg:								\
       %{!pthread:-lc}							\
       %{pthread:-lc_r}}							\
