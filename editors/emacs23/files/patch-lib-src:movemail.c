--- lib-src/movemail.c.orig	Mon Feb 14 11:29:49 2005
+++ lib-src/movemail.c	Mon Feb 14 11:33:06 2005
@@ -787,7 +787,7 @@
       mbx_delimit_begin (mbf);
       if (pop_retr (server, i, mbf) != OK)
 	{
-	  error (Errmsg, 0, 0);
+	  error ("%s", Errmsg, 0);
 	  close (mbfi);
 	  return (1);
 	}
