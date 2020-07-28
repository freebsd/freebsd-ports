--- src/libshared/src/FS.cpp.orig	2020-07-28 19:40:14 UTC
+++ src/libshared/src/FS.cpp
@@ -478,7 +478,7 @@ bool File::lock ()
 #ifdef DARWIN
                     // l_start l_len l_pid l_type   l_whence
     struct flock fl = {0,      0,    0,    F_WRLCK, SEEK_SET};
-#elif FREEBSD
+#elif defined FREEBSD
                     // l_type   l_whence  l_start  l_len  l_pid  l_sysid
     struct flock fl = {F_WRLCK, SEEK_SET, 0,       0,     0,     0 };
 #else
@@ -501,7 +501,7 @@ void File::unlock ()
 #ifdef DARWIN
                     // l_start l_len l_pid l_type   l_whence
     struct flock fl = {0,      0,    0,    F_WRLCK, SEEK_SET};
-#elif FREEBSD
+#elif defined FREEBSD
                     // l_type   l_whence  l_start  l_len  l_pid  l_sysid
     struct flock fl = {F_WRLCK, SEEK_SET, 0,       0,     0,     0 };
 #else
