--- include/iprt/string.h.orig	2018-06-29 13:08:03 UTC
+++ include/iprt/string.h
@@ -43,6 +43,11 @@
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
