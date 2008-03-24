--- sysdeps/freebsd/fsusage.c.orig	2007-06-03 16:06:05.000000000 -0400
+++ sysdeps/freebsd/fsusage.c	2008-02-09 19:50:44.000000000 -0500
@@ -10,6 +10,7 @@
 #include <unistd.h>
 #include <sys/param.h>
 #include <sys/mount.h>
+#include <sys/statvfs.h>
 #if __FreeBSD_version >= 600000 || defined(__FreeBSD_kernel__)
 #include <libgeom.h>
 #include <sys/resource.h>
@@ -21,15 +22,13 @@
 #include <string.h>
 #include <stdlib.h>
 
-void
-_glibtop_freebsd_get_fsusage_read_write(glibtop *server,
-                                        glibtop_fsusage *buf,
-                                        const char *path);
+static const unsigned long _glibtop_sysdeps_fsusage =
+(1L << GLIBTOP_FSUSAGE_BLOCKS) + (1L << GLIBTOP_FSUSAGE_BFREE)
++ (1L << GLIBTOP_FSUSAGE_BAVAIL) + (1L << GLIBTOP_FSUSAGE_FILES)
++ (1L << GLIBTOP_FSUSAGE_FFREE) + (1L << GLIBTOP_FSUSAGE_BLOCK_SIZE);
 
-void
-_glibtop_freebsd_get_fsusage_read_write(glibtop *server,
-                                        glibtop_fsusage *buf,
-                                        const char *path)
+static void
+_glibtop_get_fsusage_read_write (glibtop *server, glibtop_fsusage *buf, const char *path)
 {
         int result;
         struct statfs sfs;
@@ -135,3 +134,28 @@ _glibtop_freebsd_get_fsusage_read_write(
 #endif
         buf->flags |= (1 << GLIBTOP_FSUSAGE_READ) | (1 << GLIBTOP_FSUSAGE_WRITE);
 }
+
+void
+glibtop_get_fsusage_s(glibtop *server, glibtop_fsusage *buf, const char *path)
+{
+	struct statvfs fsd;
+
+	glibtop_init_r (&server, 0, 0);
+
+	memset (buf, 0, sizeof (glibtop_fsusage));
+
+	if (statvfs (path, &fsd) < 0)
+		return;
+
+	buf->block_size = fsd.f_frsize;
+	buf->blocks = fsd.f_blocks;
+	buf->bfree  = fsd.f_bfree;
+	buf->bavail = (fsd.f_bavail > fsd.f_bfree) ? 0 : fsd.f_bavail;
+	buf->files  = fsd.f_files;
+	buf->ffree  = fsd.f_ffree;
+
+	buf->flags = _glibtop_sysdeps_fsusage;
+
+	_glibtop_get_fsusage_read_write(server, buf, path);
+}
+
