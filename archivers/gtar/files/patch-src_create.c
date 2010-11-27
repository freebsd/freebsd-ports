$FreeBSD$

Fix bug with --one-file-system and --listed-incremental.

--- src/create.c.orig	2010-11-01 21:34:59.000000000 +0100
+++ src/create.c	2010-11-27 21:12:55.000000000 +0100
@@ -1680,7 +1680,7 @@ dump_file0 (struct tar_stat_info *st, ch
      This check is omitted if incremental_option is set *and* the
      requested file is not explicitely listed in the command line. */
 
-  if (!(incremental_option && !is_individual_file (p))
+  if (! (incremental_option && ! top_level)
       && !S_ISDIR (st->stat.st_mode)
       && OLDER_TAR_STAT_TIME (*st, m)
       && (!after_date_option || OLDER_TAR_STAT_TIME (*st, c)))
