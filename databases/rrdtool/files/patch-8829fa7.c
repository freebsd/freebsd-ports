From 8829fa758f3e585f20094cff69b32489f4cce3e7 Mon Sep 17 00:00:00 2001
From: Niclas Zeising
Date: Sun, 14 Jun 2020 11:31:33 +0200
Subject: [PATCH] rrd_open: Ignore EINVAL from posix_fallocate()

ZFS on FreeBSD (at least) does not support posix_fallocate(),
returning EINVAL instead.  Ignore this error and continue normally.
Without this change, it is not possible to resize rrd files on ZFS.

This fixes #1082

Signed-off-by: Niclas Zeising
---
 src/rrd_open.c | 8 +++++++-
 1 file changed, 7 insertions(+), 1 deletion(-)

diff --git a/src/rrd_open.c b/src/rrd_open.c
index d8005fe4..00dfb8ca 100644
--- src/rrd_open.c
+++ src/rrd_open.c
@@ -363,7 +363,13 @@ rrd_file_t *rrd_open(
          */
         int       fret =
             posix_fallocate(rrd_simple_file->fd, 0, newfile_size);
-        if (fret) {
+        /* ZFS (on FreeBSD) does not support posix_fallocate(), always returning
+         * EINVAL.  Ignore this error and continue anyway.
+         * Without this, resize isn't possible on ZFS filesystems.
+         */
+        if (fret == EINVAL) {
+            /* DO NOTHING */
+        } else if (fret) {
             rrd_set_error("posix_fallocate '%s': %s", file_name,
                           rrd_strerror(fret));
             goto out_close;
