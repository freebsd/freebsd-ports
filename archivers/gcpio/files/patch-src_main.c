--- src/main.c.orig	2015-09-12 10:57:30 UTC
+++ src/main.c
@@ -61,7 +61,8 @@ enum cpio_options {
   TO_STDOUT_OPTION,
   RENUMBER_INODES_OPTION,
   IGNORE_DEVNO_OPTION,
-  DEVICE_INDEPENDENT_OPTION
+  DEVICE_INDEPENDENT_OPTION,
+  EXTRACT_OVER_SYMLINKS
 };
 
 const char *program_authors[] =
@@ -243,6 +244,8 @@ static struct argp_option options[] = {
    N_("Create leading directories where needed"), GRID+1 },
   {"no-preserve-owner", NO_PRESERVE_OWNER_OPTION, 0, 0,
    N_("Do not change the ownership of the files"), GRID+1 },
+  {"extract-over-symlinks", EXTRACT_OVER_SYMLINKS, 0, 0,
+   N_("Force writing over symbolic links"), GRID+1 },
   {"unconditional", 'u', NULL, 0,
    N_("Replace all files unconditionally"), GRID+1 },
   {"sparse", SPARSE_OPTION, NULL, 0,
@@ -432,6 +435,10 @@ crc newc odc bin ustar tar (all-caps als
       no_chown_flag = true;
       break;
 
+    case EXTRACT_OVER_SYMLINKS:		        /* --extract-over-symlinks */
+      extract_over_symlinks = true;
+      break;
+
     case 'o':		/* Copy-out mode.  */
       if (copy_function != 0)
 	USAGE_ERROR ((0, 0, _("Mode already defined")));
