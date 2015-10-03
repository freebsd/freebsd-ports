--- ace/OS_NS_Thread.h.orig	2015-09-17 06:55:18 UTC
+++ ace/OS_NS_Thread.h
@@ -42,6 +42,12 @@
 # endif /* VxWorks and ! SMP */
 #endif
 
+# include <sys/param.h>
+#if (defined(__FreeBSD__) && ((__FreeBSD_version >= 700110 && __FreeBSD_version < 800000) || __FreeBSD_version >= 800024))
+# include <sys/cpuset.h>
+# define cpu_set_t cpuset_t
+#endif
+
 # if defined (ACE_EXPORT_MACRO)
 #   undef ACE_EXPORT_MACRO
 # endif
