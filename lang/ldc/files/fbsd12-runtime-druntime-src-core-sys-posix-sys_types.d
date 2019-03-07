--- runtime/druntime/src/core/sys/posix/sys/types.d	2019-02-15 17:20:40.000000000 +0000
+++ runtime/druntime/src/core/sys/posix/sys/types.d	2019-03-05 17:51:58.972306000 +0000
@@ -145,14 +145,13 @@
 }
 else version (FreeBSD)
 {
-    // https://github.com/freebsd/freebsd/blob/master/sys/sys/_types.h
     alias long      blkcnt_t;
-    alias uint      blksize_t;
-    alias uint      dev_t;
+    alias ulong     blksize_t;
+    alias ulong     dev_t;
     alias uint      gid_t;
-    alias uint      ino_t;
+    alias ulong     ino_t;
     alias ushort    mode_t;
-    alias ushort    nlink_t;
+    alias ulong     nlink_t;
     alias long      off_t;
     alias int       pid_t;
     //size_t (defined in core.stdc.stddef)
