--- ldc2-1.41.0-freebsd-x86_64/import/core/sys/freebsd/config.d.orig	2025-06-07 02:43:09 UTC
+++ ldc2-1.41.0-freebsd-x86_64/import/core/sys/freebsd/config.d
@@ -14,7 +14,8 @@
 // NOTE: When adding newer versions of FreeBSD, verify all current versioned
 // bindings are still compatible with the release.
 
-     version (FreeBSD_15) enum __FreeBSD_version = 1500000;
+     version (FreeBSD_16) enum __FreeBSD_version = 1600000;
+else version (FreeBSD_15) enum __FreeBSD_version = 1500000;
 else version (FreeBSD_14) enum __FreeBSD_version = 1400000;
 else version (FreeBSD_13) enum __FreeBSD_version = 1302000;
 else version (FreeBSD_12) enum __FreeBSD_version = 1204000;
