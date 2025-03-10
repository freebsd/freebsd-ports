--- libphobos/libdruntime/core/sys/freebsd/config.d.orig	2023-08-31 22:33:21 UTC
+++ libphobos/libdruntime/core/sys/freebsd/config.d
@@ -13,8 +13,10 @@ public import core.sys.posix.config;
 // __FreeBSD_version numbers are documented in the Porter's Handbook.
 // NOTE: When adding newer versions of FreeBSD, verify all current versioned
 // bindings are still compatible with the release.
-     version (FreeBSD_13) enum __FreeBSD_version = 1300000;
-else version (FreeBSD_12) enum __FreeBSD_version = 1202000;
+     version (FreeBSD_15) enum __FreeBSD_version = 1500000;
+else version (FreeBSD_14) enum __FreeBSD_version = 1401000;
+else version (FreeBSD_13) enum __FreeBSD_version = 1303000;
+else version (FreeBSD_12) enum __FreeBSD_version = 1204000;
 else version (FreeBSD_11) enum __FreeBSD_version = 1104000;
 else version (FreeBSD_10) enum __FreeBSD_version = 1004000;
 else version (FreeBSD_9)  enum __FreeBSD_version = 903000;
