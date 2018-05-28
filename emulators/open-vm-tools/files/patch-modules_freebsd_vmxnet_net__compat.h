--- modules/freebsd/vmxnet/net_compat.h.orig	2018-03-30 18:44:35 UTC
+++ modules/freebsd/vmxnet/net_compat.h
@@ -37,9 +37,14 @@
 #if __FreeBSD_version < 500016
    #define VXN_IFMULTI_FIRST LIST_FIRST
    #define VXN_IFMULTI_NEXT  LIST_NEXT
-#else /* >= 500016 */
+#else
+#if __FreeBSD_version <= 1200063
    #define VXN_IFMULTI_FIRST TAILQ_FIRST
    #define VXN_IFMULTI_NEXT  TAILQ_NEXT
+#else /* > 1200063 */
+   #define VXN_IFMULTI_FIRST CK_STAILQ_FIRST
+   #define VXN_IFMULTI_NEXT  CK_STAILQ_NEXT
+#endif /* 1200063 */
 #endif /* 500016 */
 
 #if __FreeBSD_version < 500043
