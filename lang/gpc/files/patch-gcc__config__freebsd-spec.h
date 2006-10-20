--- ./gcc/config/freebsd-spec.h.orig	Fri Oct 20 15:51:07 2006
+++ ./gcc/config/freebsd-spec.h	Fri Oct 20 15:51:23 2006
@@ -51,7 +51,13 @@
 #define FBSD_TARGET_OS_CPP_BUILTINS()					\
   do									\
     {									\
-	if (FBSD_MAJOR == 6)						\
+	if (FBSD_MAJOR == 9)						\
+	  builtin_define ("__FreeBSD__=9");			       	\
+	else if (FBSD_MAJOR == 8)					\
+	  builtin_define ("__FreeBSD__=8");			       	\
+	if (FBSD_MAJOR == 7)						\
+	  builtin_define ("__FreeBSD__=7");			       	\
+	else if (FBSD_MAJOR == 6)					\
 	  builtin_define ("__FreeBSD__=6");			       	\
 	else if (FBSD_MAJOR == 5)	       				\
 	  builtin_define ("__FreeBSD__=5");			       	\
@@ -107,12 +113,12 @@
    500016, select the appropriate libc, depending on whether we're
    doing profiling or need threads support.  At __FreeBSD_version
    500016 and later, when threads support is requested include both
-   -lc and -lc_r instead of only -lc_r.  To make matters interesting,
-   we can't actually use __FreeBSD_version provided by <osreldate.h>
-   directly since it breaks cross-compiling.  As a final twist, make
-   it a hard error if -pthread is provided on the command line and gcc
-   was configured with --disable-threads (this will help avoid bug
-   reports from users complaining about threading when they
+   -lc and the threading lib instead of only -lc_r.  To make matters
+   interesting, we can't actually use __FreeBSD_version provided by
+   <osreldate.h> directly since it breaks cross-compiling.  As a final
+   twist, make it a hard error if -pthread is provided on the command
+   line and gcc was configured with --disable-threads (this will help
+   avoid bug reports from users complaining about threading when they
    misconfigured the gcc bootstrap but are later consulting FreeBSD
    manual pages that refer to the mythical -pthread option).  */
 
@@ -129,13 +135,7 @@
     %{pg:  -lc_p}							\
   }"
 #else
-#if FBSD_MAJOR >= 5
-#define FBSD_LIB_SPEC "							\
-  %{!shared:								\
-    %{!pg: %{pthread:-lc_r} -lc}					\
-    %{pg:  %{pthread:-lc_r_p} -lc_p}					\
-  }"
-#else
+#if FBSD_MAJOR < 5
 #define FBSD_LIB_SPEC "							\
   %{!shared:								\
     %{!pg:								\
@@ -144,6 +144,12 @@
     %{pg:								\
       %{!pthread:-lc_p}							\
       %{pthread:-lc_r_p}}						\
+  }"
+#else
+#define FBSD_LIB_SPEC "							\
+  %{!shared:								\
+    %{!pg: %{pthread:-lpthread} -lc}					\
+    %{pg:  %{pthread:-lpthread_p} -lc_p}				\
   }"
 #endif
 #endif
