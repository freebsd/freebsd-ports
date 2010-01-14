--- ./medialib.c.orig	2010-01-14 21:05:31.000000000 +0100
+++ ./medialib.c	2010-01-14 21:07:02.000000000 +0100
@@ -351,7 +351,7 @@
           * last extracted meta-info from it (otherwise we ignore)
           */
 
-         if (sb.st_mtim.tv_sec > mdb.library->files[i]->last_updated) {
+         if (sb.st_mtime > mdb.library->files[i]->last_updated) {
 
             mi = mi_extract(filename);
             if (mi == NULL) {
@@ -457,7 +457,7 @@
             if (idx != -1) {
                /* file already exists in library database - update */
 
-               if (ftsent->fts_statp->st_mtim.tv_sec >
+               if (ftsent->fts_statp->st_mtime >
                    mdb.library->files[idx]->last_updated) {
 
                   /* file has been modified since we last extracted info */
