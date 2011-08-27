--- src/cache.cpp.orig	2011-07-27 21:29:16.000000000 +0900
+++ src/cache.cpp	2011-08-23 22:52:30.000000000 +0900
@@ -816,14 +816,14 @@
     if( stat( to_locale_cstr( path ), &buf_stat ) != 0 ) return false;
     if( S_ISREG( buf_stat.st_mode ) ){
 
-        struct timespec ts[2];         
+        struct timeval tv[2];
 
-        ts[0].tv_sec  = buf_stat.st_atime;
-        ts[0].tv_nsec = buf_stat.st_atim.tv_nsec;
-        ts[1].tv_sec  = mtime;
-        ts[1].tv_nsec = 0;
+        tv[0].tv_sec  = buf_stat.st_atime;
+        tv[0].tv_usec = buf_stat.st_atimespec.tv_nsec / 1000;
+        tv[1].tv_sec  = mtime;
+        tv[1].tv_usec = 0;
 
-        if( ! utimensat( AT_FDCWD, to_locale_cstr( path ), ts, AT_SYMLINK_NOFOLLOW ) ) return true;
+        if( ! lutimes(to_locale_cstr( path ), tv ) ) return true;
     }
 
     return false;