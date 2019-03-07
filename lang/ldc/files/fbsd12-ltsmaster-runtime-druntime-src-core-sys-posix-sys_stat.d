--- ltsmaster/runtime/druntime/src/core/sys/posix/sys/stat.d	2018-08-21 18:55:47.000000000 +0000
+++ ltsmaster/runtime/druntime/src/core/sys/posix/sys/stat.d	2019-03-06 04:13:18.999142000 +0000
@@ -714,32 +714,42 @@
 {
     struct stat_t
     {
-        dev_t       st_dev;
-        ino_t       st_ino;
-        mode_t      st_mode;
-        nlink_t     st_nlink;
-        uid_t       st_uid;
-        gid_t       st_gid;
-        dev_t       st_rdev;
+        dev_t     st_dev;
+        ino_t     st_ino;
+        nlink_t   st_nlink;
+        mode_t    st_mode;
+        short st_padding0;
+        uid_t     st_uid;
+        gid_t     st_gid;
+        int st_padding1;
+        dev_t     st_rdev;
 
+        version(X86) int st_atim_ext;
+
         time_t      st_atime;
         c_long      __st_atimensec;
+
+        version(X86) int st_mtim_ext;
+
         time_t      st_mtime;
         c_long      __st_mtimensec;
+
+        version(X86) int st_ctim_ext;
+
         time_t      st_ctime;
         c_long      __st_ctimensec;
 
-        off_t       st_size;
-        blkcnt_t    st_blocks;
-        blksize_t   st_blksize;
-        fflags_t    st_flags;
-        uint        st_gen;
-        int         st_lspare;
+        version(X86) int st_btim_ext;
 
         time_t      st_birthtime;
         c_long      st_birthtimensec;
 
-        ubyte[16 - timespec.sizeof] padding;
+	off_t     st_size;
+        blkcnt_t st_blocks;
+        blksize_t st_blksize;
+        fflags_t  st_flags;
+        ulong st_gen;
+        ulong[10] st_spare;
     }
 
     enum S_IRUSR    = 0x100; // octal 0000400
