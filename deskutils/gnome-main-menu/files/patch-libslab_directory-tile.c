--- libslab/directory-tile.c.orig	2008-07-06 22:40:19.000000000 -0400
+++ libslab/directory-tile.c	2008-07-06 22:40:33.000000000 -0400
@@ -672,5 +672,5 @@ static void
 disown_spawned_child (gpointer user_data)
 {
 	setsid  ();
-	setpgrp ();
+	setpgrp (0, 0);
 }
