--- src/efivarfs.c.orig	2024-01-31 20:08:46 UTC
+++ src/efivarfs.c
@@ -9,20 +9,32 @@
 #include <err.h>
 #include <errno.h>
 #include <fcntl.h>
-#include <linux/magic.h>
+#if defined(__linux__)
+#  include <linux/magic.h>
+#endif
 #include <stdio.h>
 #include <stdlib.h>
 #include <string.h>
 #include <sys/mman.h>
 #include <sys/types.h>
+#include <sys/param.h>
+#include <sys/mount.h>
 #include <sys/stat.h>
 #include <sys/uio.h>
-#include <sys/vfs.h>
+#if defined(__linux__)
+#  include <sys/vfs.h>
+#endif
 #include <unistd.h>
 
+#if defined(__FreeBSD__)
+#  undef LIST_HEAD
+#endif
+
 #include "efivar.h"
 
-#include <linux/fs.h>
+#if defined(__linux__)
+#  include <linux/fs.h>
+#endif
 
 #ifndef EFIVARFS_MAGIC
 #  define EFIVARFS_MAGIC 0xde5e81e4
@@ -102,6 +114,7 @@ efivarfs_set_fd_immutable(int fd, int immutable)
 static int
 efivarfs_set_fd_immutable(int fd, int immutable)
 {
+#if defined(__linux__)
 	unsigned int flags;
 	int rc = 0;
 
@@ -124,11 +137,42 @@ efivarfs_set_fd_immutable(int fd, int immutable)
 	}
 
 	return rc;
+#elif defined(__FreeBSD__)
+	struct stat sb;
+	int rc = 0;
+	unsigned long flags;
+
+	if (fstat(fd, &sb) == -1) {
+		if (errno == EBADF)
+			rc = 0;
+		else
+			efi_error("fstat(%d) failed", fd);
+		return rc;
+	}
+
+	flags = sb.st_flags;
+
+	if ((immutable && !(flags & UF_IMMUTABLE)) ||
+	    (!immutable && (flags & UF_IMMUTABLE))) {
+		if (immutable)
+			flags |= UF_IMMUTABLE;
+		else
+			flags &= ~UF_IMMUTABLE;
+
+		if (chflagsat(fd, "", flags, AT_EMPTY_PATH) == -1) {
+			efi_error("chflagsat(%d) failed\n", fd);
+			rc = -1;
+		}
+	}
+
+	return rc;
+#endif
 }
 
 static int
 efivarfs_make_fd_mutable(int fd, unsigned long *orig_attrs)
 {
+#if defined(__linux__)
 	unsigned long mutable_attrs = 0;
 
 	*orig_attrs = 0;
@@ -145,6 +189,26 @@ efivarfs_make_fd_mutable(int fd, unsigned long *orig_a
 		return -1;
 
 	return 0;
+#elif defined(__FreeBSD__)
+	struct stat sb;
+
+	*orig_attrs = 0;
+
+	if (fstat(fd, &sb) == -1)
+		return -1;
+
+	*orig_attrs = sb.st_flags;
+
+	// if the file is not immutable, nothing to do
+	if ((sb.st_flags & UF_IMMUTABLE) == 0)
+		return 0;
+
+	// remove user immutable flag
+	if (chflagsat(fd, "", sb.st_flags & ~UF_IMMUTABLE, AT_EMPTY_PATH) == -1)
+		return -1;
+
+	return 0;
+#endif
 }
 
 static int
@@ -375,10 +439,17 @@ efivarfs_set_variable(efi_guid_t guid, const char *nam
 			goto err;
 		}
 
+#if defined(__linux__)
 		/* if the file is indeed immutable, clear and remember it */
 		if (efivarfs_make_fd_mutable(rfd, &orig_attrs) == 0 &&
 		    (orig_attrs & FS_IMMUTABLE_FL))
 			restore_immutable_fd = rfd;
+#elif defined(__FreeBSD__)
+		/* if the file is indeed immutable, clear and remember it */
+		if (efivarfs_make_fd_mutable(rfd, &orig_attrs) == 0 &&
+		    (orig_attrs & UF_IMMUTABLE))
+			restore_immutable_fd = rfd;
+#endif
 	}
 
 	/*
@@ -414,9 +485,15 @@ efivarfs_set_variable(efi_guid_t guid, const char *nam
 	 * immediately, and the write() below would fail otherwise.
 	 */
 	if (rfd == -1) {
+#if defined(__linux__)
 		if (efivarfs_make_fd_mutable(wfd, &orig_attrs) == 0 &&
 		    (orig_attrs & FS_IMMUTABLE_FL))
 			restore_immutable_fd = wfd;
+#elif defined(__FreeBSD__)
+		if (efivarfs_make_fd_mutable(wfd, &orig_attrs) == 0 &&
+		    (orig_attrs & UF_IMMUTABLE))
+			restore_immutable_fd = wfd;
+#endif
 	} else {
 		/* make sure rfd and wfd refer to the same file */
 		struct stat wfd_stat;
@@ -452,7 +529,11 @@ err:
 	if (ret == -1 && rfd == -1 && wfd != -1 && unlink(path) == -1)
 		efi_error("failed to unlink %s", path);
 
+#if defined(__linux__)
 	ioctl(restore_immutable_fd, FS_IOC_SETFLAGS, &orig_attrs);
+#elif defined(__FreeBSD__)
+	chflagsat(restore_immutable_fd, "", orig_attrs, AT_EMPTY_PATH);
+#endif
 
 	if (wfd >= 0)
 		close(wfd);
