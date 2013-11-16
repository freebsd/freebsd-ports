--- modules/freebsd/vmxnet/if_vxn.c.orig	2013-11-16 03:47:08.000000000 +0000
+++ modules/freebsd/vmxnet/if_vxn.c	2013-11-16 03:51:10.000000000 +0000
@@ -76,6 +76,10 @@
 #include <pci/pcivar.h>
 #endif
 
+#if __FreeBSD_version >= 1100001
+#include <net/if_var.h>
+#endif
+
 /* define INLINE the way gcc likes it */
 #define INLINE __inline__
 
