
$FreeBSD$

--- pal/unix/file/file.c	2002/04/09 22:17:33	1.1
+++ pal/unix/file/file.c	2002/04/09 22:19:43
@@ -2822,18 +2822,10 @@
     }
     else
     {
-        /* give write permission to anyone that has read permission */
+        /* give write permission to owner if it has read permission */
         if ( new_mode & S_IRUSR )
         {
             new_mode |= S_IWUSR;
-        }
-        if ( new_mode & S_IRGRP )
-        {
-            new_mode |= S_IWGRP;
-        }
-        if ( new_mode & S_IROTH )
-        {
-            new_mode |= S_IWOTH;
         }
     }
     TRACE("new mode is 0x%lx\n", new_mode);
