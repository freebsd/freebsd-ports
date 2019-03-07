--- runtime/druntime/src/core/sys/freebsd/sys/mount.d	2019-03-05 17:38:00.882617000 +0000
+++ runtime/druntime/src/core/sys/freebsd/sys/mount.d	2019-03-05 17:38:53.720464000 +0000
@@ -32,8 +32,8 @@
 }
 
 enum MFSNAMELEN = 16;
-enum MNAMELEN   = 88;
-enum STATFS_VERSION = 0x20030518;
+enum MNAMELEN   = 1024;
+enum STATFS_VERSION = 0x20140518;
 
 struct statfs_t
 {
