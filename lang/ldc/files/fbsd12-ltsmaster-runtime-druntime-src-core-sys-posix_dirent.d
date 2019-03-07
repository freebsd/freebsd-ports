--- ltsmaster/runtime/druntime/src/core/sys/posix/dirent.d	2019-03-06 04:07:06.836421000 +0000
+++ ltsmaster/runtime/druntime/src/core/sys/posix/dirent.d	2019-03-06 04:08:34.306001000 +0000
@@ -131,10 +131,12 @@
     align(4)
     struct dirent
     {
-        uint      d_fileno;
+        ino_t     d_fileno;
+        off_t     d_off;
         ushort    d_reclen;
         ubyte     d_type;
-        ubyte     d_namlen;
+        ushort    d_namlen;
+        ushort    d_pad1;
         char[256] d_name;
     }
 
