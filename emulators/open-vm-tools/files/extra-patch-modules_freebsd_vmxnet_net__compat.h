--- modules/freebsd/vmxnet/net_compat.h.orig	2018-05-23 22:11:09 UTC
+++ modules/freebsd/vmxnet/net_compat.h
@@ -38,8 +38,8 @@
    #define VXN_IFMULTI_FIRST LIST_FIRST
    #define VXN_IFMULTI_NEXT  LIST_NEXT
 #else /* >= 500016 */
-   #define VXN_IFMULTI_FIRST TAILQ_FIRST
-   #define VXN_IFMULTI_NEXT  TAILQ_NEXT
+   #define VXN_IFMULTI_FIRST CK_STAILQ_FIRST
+   #define VXN_IFMULTI_NEXT  CK_STAILQ_NEXT
 #endif /* 500016 */
 
 #if __FreeBSD_version < 500043
