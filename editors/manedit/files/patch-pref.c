
$FreeBSD$

--- pref.c	2001/02/09 13:07:09	1.1
+++ pref.c	2001/02/09 13:08:32
@@ -1709,15 +1709,15 @@
 	{
 	    gchar *text[2];
 
-	    text[0] = "/usr/man";
+	    text[0] = "/usr/share/man";
 	    text[1] = "Global";
 	    gtk_clist_append(GTK_CLIST(w), text);
 
-            text[0] = "/usr/local/man";
+            text[0] = LOCALBASE"/man";
             text[1] = "Local";
             gtk_clist_append(GTK_CLIST(w), text);
 
-            text[0] = "/usr/X11R6/man";
+            text[0] = X11BASE"/man";
             text[1] = "X Window Systems";
             gtk_clist_append(GTK_CLIST(w), text);
 	}
