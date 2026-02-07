Index: Wnn/jserver/initjserv.c
===================================================================
RCS file: /home/cvs/private/hrs/freewnn/Wnn/jserver/initjserv.c,v
retrieving revision 1.1.1.1
retrieving revision 1.3
diff -u -p -r1.1.1.1 -r1.3
--- Wnn/jserver/initjserv.c	20 Dec 2008 07:13:30 -0000	1.1.1.1
+++ Wnn/jserver/initjserv.c	2 Jan 2009 11:46:51 -0000	1.3
@@ -154,6 +154,7 @@ read_default (void)
   char param[EXPAND_PATH_LENGTH +1];
   char *word;
   int i, num, *v[17];
+  int lindex = 0;
 
   strcpy (jserver_dir, JSERVER_DIR);
 
@@ -215,6 +216,15 @@ read_default (void)
 	    }
           log_debug ("max_client=%d", max_client);
         }
+      else if (listenaddr[lindex][0] == '\0'
+	       && strcmp(code, "listenaddr") == 0) {
+	      num = sscanf (data, "%s %s ", code, listenaddr[lindex]);
+	      if (num != 2) {
+		      log_err ("command %s invalid.", code);
+		      continue;
+	      }
+	      lindex++;
+      }
       else if (strcmp (code, "max_sticky_env") == 0)
         {
           num = sscanf (data, "%s %d ", code, &max_sticky_env);
@@ -305,7 +315,9 @@ read_default_files (void)
     }
   fclose (fp);
 
+  /*
   printf ("Finished Reading Files\n");
+  */
 
   return (0);
 }
@@ -340,7 +352,9 @@ read_default_file (char* buffer, size_t 
 
   files[fid].localf = LOCAL;
   strcpy (files[fid].name, buffer);
+  /*
   printf ("Reading %s\t Fid = %d\n", buffer, fid);
+  */
   if (read_file (&files[fid]) == -1)
     {
       printf ("Error reading %s\n", buffer);
