$FreeBSD$

Fix bug with --one-file-system and --listed-incremental.

--- src/incremen.c.orig	2010-10-24 20:07:55.000000000 +0200
+++ src/incremen.c	2010-11-27 21:08:05.000000000 +0100
@@ -426,7 +426,6 @@ procdir (const char *name_buffer, struct
 {
   struct directory *directory;
   struct stat *stat_data = &st->stat;
-  dev_t device = st->parent ? st->parent->stat.st_dev : 0;
   bool nfs = NFS_FILE_STAT (*stat_data);
 
   if ((directory = find_directory (name_buffer)) != NULL)
@@ -540,11 +539,8 @@ procdir (const char *name_buffer, struct
 	}
     }
 
-  /* If the directory is on another device and --one-file-system was given,
-     omit it... */
-  if (one_file_system_option && device != stat_data->st_dev
-      /* ... except if it was explicitely given in the command line */
-      && !is_individual_file (name_buffer))
+  if (one_file_system_option && st->parent
+      && stat_data->st_dev != st->parent->stat.st_dev)
     /* FIXME:
 	WARNOPT (WARN_XDEV,
 		 (0, 0,
