--- Wnn/jserver/initjserv.c.orig	Wed Dec  7 18:33:51 2005
+++ Wnn/jserver/initjserv.c	Wed Dec  7 18:34:43 2005
@@ -305,7 +305,9 @@
     }
   fclose (fp);
 
+  /*
   printf ("Finished Reading Files\n");
+  */
 
   return (0);
 }
@@ -340,7 +342,9 @@
 
   files[fid].localf = LOCAL;
   strcpy (files[fid].name, buffer);
+  /*
   printf ("Reading %s\t Fid = %d\n", buffer, fid);
+  */
   if (read_file (&files[fid]) == -1)
     {
       printf ("Error reading %s\n", buffer);
