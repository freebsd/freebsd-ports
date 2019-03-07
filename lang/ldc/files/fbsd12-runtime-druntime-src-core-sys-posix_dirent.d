--- runtime/druntime/src/core/sys/posix/dirent.d	2019-03-05 17:39:54.822687000 +0000
+++ runtime/druntime/src/core/sys/posix/dirent.d	2019-03-05 17:41:19.267583000 +0000
@@ -152,11 +152,13 @@
     align(4)
     struct dirent
     {
-        uint      d_fileno;
-        ushort    d_reclen;
-        ubyte     d_type;
-        ubyte     d_namlen;
-        char[256] d_name;
+         ino_t     d_fileno;
+         off_t     d_off;
+         ushort    d_reclen;
+         ubyte     d_type;
+         ushort    d_namlen;
+         ushort    d_pad1;
+         char[256] d_name;
     }
 
     alias void* DIR;
