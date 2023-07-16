--- lib/fsm.c.orig	2023-03-13 14:33:50 UTC
+++ lib/fsm.c
@@ -1014,7 +1014,7 @@
                     rc = RPMERR_UNKNOWN_FILETYPE;
             }
 
-setmeta:
+setmeta:;
 	    /* Special files require path-based ops */
 	    int mayopen = S_ISREG(fp->sb.st_mode) || S_ISDIR(fp->sb.st_mode);
 	    if (!rc && fd == -1 && mayopen) {
