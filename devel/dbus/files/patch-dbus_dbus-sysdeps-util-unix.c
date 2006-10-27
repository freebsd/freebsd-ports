--- dbus/dbus-sysdeps-util-unix.c.orig	Thu Oct 26 22:02:29 2006
+++ dbus/dbus-sysdeps-util-unix.c	Thu Oct 26 22:02:52 2006
@@ -42,6 +42,7 @@
 #include <sys/socket.h>
 #include <dirent.h>
 #include <sys/un.h>
+#include <limits.h>
 
 #ifndef O_BINARY
 #define O_BINARY 0
@@ -502,7 +503,7 @@ static dbus_bool_t
 dirent_buf_size(DIR * dirp, size_t *size)
 {
  long name_max;
-#   if defined(HAVE_FPATHCONF) && defined(HAVE_DIRFD) \
+#   if defined(HAVE_FPATHCONF) && ( defined(HAVE_DIRFD) || defined(dirfd) )\
     && defined(_PC_NAME_MAX)
      name_max = fpathconf(dirfd(dirp), _PC_NAME_MAX);
      if (name_max == -1)
