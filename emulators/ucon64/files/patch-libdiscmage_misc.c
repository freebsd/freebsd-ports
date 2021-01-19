Fixes a crash in change_mem2() on 64-bit platforms.  That function is used for
patching functionality.

This patch is already incorporated at upstream and will become obsolete with
the next release.

--- libdiscmage/misc.c.orig	2020-07-03 08:13:04 UTC
+++ libdiscmage/misc.c
@@ -1874,7 +1874,7 @@ change_mem2 (char *buf, size_t bufsize, char *searchst
 
           if (strpos == pos_1st_esc)
             setindex = 0;                       // reset argument pointer
-          if (pos_1st_esc == (unsigned int) -1)
+          if (pos_1st_esc == (size_t) -1)
             pos_1st_esc = strpos;
 
           set = sets[setindex].data;            // get next set of characters
