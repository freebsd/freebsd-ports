--- include/iprt/string.h.orig	2025-08-13 19:37:25 UTC
+++ include/iprt/string.h
@@ -57,6 +57,11 @@
 #elif defined(RT_OS_FREEBSD) && defined(_KERNEL)
   RT_C_DECLS_BEGIN
 # include <sys/libkern.h>
+  /*
+   * Kludge for the FreeBSD kernel:
+   *  sys/libkern.h includes sys/param.h via sys/systm.h since r335879.
+   */
+# undef PVM
   RT_C_DECLS_END
 
 #elif defined(RT_OS_NETBSD) && defined(_KERNEL)
