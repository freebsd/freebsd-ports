--- ltsmaster/runtime/druntime/src/core/sys/posix/sys/types.d	2019-03-06 04:17:35.909692000 +0000
+++ ltsmaster/runtime/druntime/src/core/sys/posix/sys/types.d	2019-03-06 04:18:41.162430000 +0000
@@ -124,12 +124,12 @@
 else version( FreeBSD )
 {
     alias long      blkcnt_t;
-    alias uint      blksize_t;
-    alias uint      dev_t;
+    alias ulong      blksize_t;
+    alias ulong      dev_t;
     alias uint      gid_t;
-    alias uint      ino_t;
+    alias ulong      ino_t;
     alias ushort    mode_t;
-    alias ushort    nlink_t;
+    alias ulong    nlink_t;
     alias long      off_t;
     alias int       pid_t;
     //size_t (defined in core.stdc.stddef)
