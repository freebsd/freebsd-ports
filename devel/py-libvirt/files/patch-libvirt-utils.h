--- libvirt-utils.h.orig	2013-12-22 12:53:26.000000000 +0100
+++ libvirt-utils.h	2013-12-22 13:00:31.000000000 +0100
@@ -54,6 +54,15 @@
     ((size_t) (sizeof (ptrdiff_t) <= sizeof (size_t) ? -1 : -2) / (s) < (n))
 
 
+#ifndef __GNUC_PREREQ
+# if defined  __GNUC__ && defined __GNUC_MINOR__
+#  define __GNUC_PREREQ(maj, min) \
+	((__GNUC__ << 16) + __GNUC_MINOR__ >= ((maj) << 16) + (min))
+# else
+#  define __GNUC_PREREQ(maj, min) 0
+# endif
+#endif /* __GNUC_PREREQ */
+
 /* The __attribute__((__warn_unused_result__)) feature
    is available in gcc versions 3.4 and newer,
    while the typeof feature has been available since 2.7 at least.  */
