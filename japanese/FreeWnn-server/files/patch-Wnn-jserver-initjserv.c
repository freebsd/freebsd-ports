Index: Wnn/jserver/initjserv.c
===================================================================
RCS file: /home/cvs/private/hrs/freewnn/Wnn/jserver/initjserv.c,v
retrieving revision 1.1
diff -d -u -I\$FreeBSD: /tmp/pcvs/ports/japanese/FreeWnn-server/files/patch-Wnn-jserver-initjserv.c,v 1.3 2009-01-02 11:49:48 hrs Exp $ -I\$NetBSD:.*\$ -I\$OpenBSD:.*\$ -I\$DragonFly:.*\$ -I\$Id:.*\$ -I\$Translation:.*\$ -I\$hrs:.*\$ -w -r1.1 initjserv.c
--- Wnn/jserver/initjserv.c	20 Dec 2008 07:13:30 -0000	1.1
+++ Wnn/jserver/initjserv.c	2 Jan 2009 11:14:37 -0000
@@ -154,6 +154,7 @@
   char param[EXPAND_PATH_LENGTH +1];
   char *word;
   int i, num, *v[17];
+  int lindex = 0;
 
   strcpy (jserver_dir, JSERVER_DIR);
 
@@ -215,6 +216,15 @@
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
@@ -305,7 +315,9 @@
     }
   fclose (fp);
 
+  /*
   printf ("Finished Reading Files\n");
+  */
 
   return (0);
 }
@@ -340,7 +352,9 @@
 
   files[fid].localf = LOCAL;
   strcpy (files[fid].name, buffer);
+  /*
   printf ("Reading %s\t Fid = %d\n", buffer, fid);
+  */
   if (read_file (&files[fid]) == -1)
     {
       printf ("Error reading %s\n", buffer);
