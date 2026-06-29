--- src/rrd_open.c.orig	2024-07-29 08:43:48 UTC
+++ src/rrd_open.c
@@ -372,7 +372,7 @@ rrd_file_t *rrd_open(
          * EINVAL.  Ignore this error and continue anyway.
          * Without this, resize isn't possible on ZFS filesystems.
          */
-        if (fret == EINVAL) {
+        if (fret == EINVAL || fret == EOPNOTSUPP) {
             /* DO NOTHING */
         } else if (fret) {
             rrd_set_error("posix_fallocate '%s': %s", file_name,
