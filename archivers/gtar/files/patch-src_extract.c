$FreeBSD$

FreeBSD produces errno == EMLINK for open("symlink", O_NOFOLLOW|...).

--- src/extract.c.orig	2010-11-23 16:56:47.000000000 +0100
+++ src/extract.c	2010-11-23 16:57:04.000000000 +0100
@@ -609,6 +609,7 @@ maybe_recoverable (char *file_name, bool
   switch (e)
     {
     case ELOOP:
+    case EMLINK:
       if (! regular
 	  || old_files_option != OVERWRITE_OLD_FILES || dereference_option)
 	break;
