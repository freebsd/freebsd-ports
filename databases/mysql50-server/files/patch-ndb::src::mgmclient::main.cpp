--- ndb/src/mgmclient/main.cpp.orig	Mon Jan 10 15:36:57 2005
+++ ndb/src/mgmclient/main.cpp	Mon Jan 10 15:37:26 2005
@@ -122,7 +122,7 @@
   }
 #ifdef HAVE_READLINE
   /* Get a line from the user. */
-  line_read = readline (prompt);    
+  line_read = readline ((char *)prompt);    
   /* If the line has any text in it, save it on the history. */
   if (line_read && *line_read)
     add_history (line_read);
