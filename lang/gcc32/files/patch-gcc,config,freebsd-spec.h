--- gcc/config/freebsd-spec.h.orig	Tue Mar  2 14:34:55 2004
+++ gcc/config/freebsd-spec.h	Fri Dec 17 11:22:26 2004
@@ -130,11 +130,20 @@
   }"
 #else
 #if FBSD_MAJOR >= 5
+#include <sys/param.h>
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
+    %{pg:  %{pthread:-lpthread_p} -lc_p}				\
+  }"
+#endif	/* deal with FreeBSD 5.0 - 5.2.1 */
 #else
 #define FBSD_LIB_SPEC "							\
   %{!shared:								\
