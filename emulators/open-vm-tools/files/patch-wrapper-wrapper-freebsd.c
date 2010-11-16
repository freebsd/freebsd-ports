--- vmware-user-suid-wrapper/wrapper-freebsd.c.orig	2010-10-20 05:19:54.000000000 +0900
+++ vmware-user-suid-wrapper/wrapper-freebsd.c	2010-11-16 17:52:55.000000000 +0900
@@ -116,7 +116,7 @@
    /*
     * Kldload(2) will handle module search paths for us.
     */
-   if (kldload(MODULE_NAME) == -1) {
+   if (kldload(VMWARE_KMOD_DIR "/" MODULE_NAME ".ko") == -1) {
       Error("failed to load vmblock: %s\n", strerror(errno));
       return FALSE;
    }
