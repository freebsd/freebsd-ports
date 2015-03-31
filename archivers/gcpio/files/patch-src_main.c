--- src/main.c.orig	2010-02-12 11:35:09 UTC
+++ src/main.c
@@ -57,7 +57,8 @@ enum cpio_options {
   FORCE_LOCAL_OPTION,            
   DEBUG_OPTION,                  
   BLOCK_SIZE_OPTION,             
-  TO_STDOUT_OPTION
+  TO_STDOUT_OPTION,
+  EXTRACT_OVER_SYMLINKS
 };
 
 const char *program_authors[] =
@@ -222,6 +223,8 @@ static struct argp_option options[] = {
    N_("Create leading directories where needed"), GRID+1 },
   {"no-preserve-owner", NO_PRESERVE_OWNER_OPTION, 0, 0,
    N_("Do not change the ownership of the files"), GRID+1 },
+  {"extract-over-symlinks", EXTRACT_OVER_SYMLINKS, 0, 0,
+   N_("Force writing over symbolic links"), GRID+1 },
   {"unconditional", 'u', NULL, 0,
    N_("Replace all files unconditionally"), GRID+1 },
   {"sparse", SPARSE_OPTION, NULL, 0,
@@ -412,6 +415,10 @@ crc newc odc bin ustar tar (all-caps als
       no_chown_flag = true;
       break;
 
+    case EXTRACT_OVER_SYMLINKS:		        /* --extract-over-symlinks */
+      extract_over_symlinks = true;
+      break;
+
     case 'o':		/* Copy-out mode.  */
       if (copy_function != 0)
 	error (PAXEXIT_FAILURE, 0, _("Mode already defined"));
