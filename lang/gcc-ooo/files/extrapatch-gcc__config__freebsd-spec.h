--- gcc-3.4.1/gcc/config/freebsd-spec.h.orig	Sat Nov  6 23:39:36 2004
+++ gcc-3.4.1/gcc/config/freebsd-spec.h	Sat Nov  6 23:39:59 2004
@@ -132,8 +132,8 @@
 #if FBSD_MAJOR >= 5
 #define FBSD_LIB_SPEC "							\
   %{!shared:								\
-    %{!pg: %{pthread:-lc_r} -lc}					\
-    %{pg:  %{pthread:-lc_r_p} -lc_p}					\
+    %{!pg: %{pthread:-lpthread} -lc}					\
+    %{pg:  %{pthread:-lpthread_p} -lc_p}					\
   }"
 #else
 #define FBSD_LIB_SPEC "							\
