--- Wnn/jserver/initjserv.c.orig	2003-05-12 03:43:15.000000000 +0900
+++ Wnn/jserver/initjserv.c	2008-10-30 16:01:50.000000000 +0900
@@ -215,6 +215,15 @@
 	    }
           log_debug ("max_client=%d", max_client);
         }
+      else if (listenaddr[0] == '\0' && strcmp (code, "listenaddr") == 0)
+        {
+          num = sscanf (data, "%s %s ", code, &listenaddr);
+	  if (num != 2)
+	    {
+	      log_err ("command %s invalid.", code);
+	      continue;
+	    }
+	}
       else if (strcmp (code, "max_sticky_env") == 0)
         {
           num = sscanf (data, "%s %d ", code, &max_sticky_env);
@@ -305,7 +314,9 @@
     }
   fclose (fp);
 
+  /*
   printf ("Finished Reading Files\n");
+  */
 
   return (0);
 }
@@ -340,7 +351,9 @@
 
   files[fid].localf = LOCAL;
   strcpy (files[fid].name, buffer);
+  /*
   printf ("Reading %s\t Fid = %d\n", buffer, fid);
+  */
   if (read_file (&files[fid]) == -1)
     {
       printf ("Error reading %s\n", buffer);
