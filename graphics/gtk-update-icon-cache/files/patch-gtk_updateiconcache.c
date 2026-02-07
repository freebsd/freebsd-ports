------------------------------------------------------------------------
r207332 | marcus | 2008-02-16 16:36:43 +0000 (Sat, 16 Feb 2008) | 5 lines

Restore the behavior of unlinking invalid icon cache files to prevent
leftovers.

reported by:	pointyhat via pav

--- gtk/updateiconcache.c.orig	2020-04-29 20:52:16 UTC
+++ gtk/updateiconcache.c
@@ -1548,7 +1548,7 @@ opentmp:
   if (!validate_file (tmp_cache_path))
     {
       g_printerr (_("The generated cache was invalid.\n"));
-      /*g_unlink (tmp_cache_path);*/
+      g_unlink (tmp_cache_path);
       exit (1);
     }
 
