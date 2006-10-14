--- dbus/dbus-sysdeps-util-unix.c.orig	Sat Oct  7 12:33:47 2006
+++ dbus/dbus-sysdeps-util-unix.c	Sat Oct  7 12:34:13 2006
@@ -502,7 +502,7 @@ static dbus_bool_t
 dirent_buf_size(DIR * dirp, size_t *size)
 {
  long name_max;
-#   if defined(HAVE_FPATHCONF) && defined(HAVE_DIRFD) \
+#   if defined(HAVE_FPATHCONF) && ( defined(HAVE_DIRFD) || defined(dirfd) )\
     && defined(_PC_NAME_MAX)
      name_max = fpathconf(dirfd(dirp), _PC_NAME_MAX);
      if (name_max == -1)
