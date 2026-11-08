The AT_NO_AUTOMOUNT seems to be a Linux-only thing...

	-mi

--- libs/filesystem/src/operations.cpp.orig	2026-04-15 14:38:54 UTC
+++ libs/filesystem/src/operations.cpp
@@ -353,7 +353,7 @@ int statx_fstatat(int dirfd, const char* path, int fla
 int statx_fstatat(int dirfd, const char* path, int flags, unsigned int mask, struct ::statx* stx)
 {
     struct ::stat st;
-    flags &= AT_EMPTY_PATH | AT_NO_AUTOMOUNT | AT_SYMLINK_NOFOLLOW;
+    flags &= AT_EMPTY_PATH | AT_SYMLINK_NOFOLLOW;
     int res = ::fstatat(dirfd, path, &st, flags);
     if (BOOST_LIKELY(res == 0))
     {
@@ -506,7 +506,7 @@ file_status status_impl
     int err = invoke_statx(basedir_fd, p.c_str(), AT_NO_AUTOMOUNT, STATX_TYPE | STATX_MODE, &path_stat);
 #elif defined(BOOST_FILESYSTEM_HAS_POSIX_AT_APIS)
     struct ::stat path_stat;
-    int err = ::fstatat(basedir_fd, p.c_str(), &path_stat, AT_NO_AUTOMOUNT);
+    int err = ::fstatat(basedir_fd, p.c_str(), &path_stat, 0);
 #else
     struct ::stat path_stat;
     int err = ::stat(p.c_str(), &path_stat);
@@ -567,7 +567,7 @@ file_status symlink_status_impl
     int err = invoke_statx(basedir_fd, p.c_str(), AT_SYMLINK_NOFOLLOW | AT_NO_AUTOMOUNT, STATX_TYPE | STATX_MODE, &path_stat);
 #elif defined(BOOST_FILESYSTEM_HAS_POSIX_AT_APIS)
     struct ::stat path_stat;
-    int err = ::fstatat(basedir_fd, p.c_str(), &path_stat, AT_SYMLINK_NOFOLLOW | AT_NO_AUTOMOUNT);
+    int err = ::fstatat(basedir_fd, p.c_str(), &path_stat, AT_SYMLINK_NOFOLLOW);
 #else
     struct ::stat path_stat;
     int err = ::lstat(p.c_str(), &path_stat);
