--- gcc/config/freebsd-spec.h.orig	Tue Mar  2 14:34:55 2004
+++ gcc/config/freebsd-spec.h	Thu Dec 16 10:19:11 2004
@@ -132,8 +132,8 @@
 #if FBSD_MAJOR >= 5
 #define FBSD_LIB_SPEC "							\
   %{!shared:								\
-    %{!pg: %{pthread:-lc_r} -lc}					\
-    %{pg:  %{pthread:-lc_r_p} -lc_p}					\
+    %{!pg: %{pthread:-lpthread} -lc}					\
+    %{pg:  %{pthread:-lpthread} -lc_p}					\
   }"
 #else
 #define FBSD_LIB_SPEC "							\
