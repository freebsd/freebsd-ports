--- runtime/druntime/src/core/sys/freebsd/config.d.orig	2025-06-07 02:40:52 UTC
+++ runtime/druntime/src/core/sys/freebsd/config.d
@@ -14,7 +14,8 @@ public import core.sys.posix.config;
 // NOTE: When adding newer versions of FreeBSD, verify all current versioned
 // bindings are still compatible with the release.
 
-     version (FreeBSD_15) enum __FreeBSD_version = 1500000;
+     version (FreeBSD_16) enum __FreeBSD_version = 1600000;
+else version (FreeBSD_15) enum __FreeBSD_version = 1500000;
 else version (FreeBSD_14) enum __FreeBSD_version = 1400000;
 else version (FreeBSD_13) enum __FreeBSD_version = 1302000;
 else version (FreeBSD_12) enum __FreeBSD_version = 1204000;
