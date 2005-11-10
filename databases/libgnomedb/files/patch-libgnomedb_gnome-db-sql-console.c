
$FreeBSD$

--- libgnomedb/gnome-db-sql-console.c.orig
+++ libgnomedb/gnome-db-sql-console.c
@@ -596,8 +596,8 @@
 
 	/* help */
 	if (!cmde_ok && !strcmp (pcmde, "?")) {
-		cmde_ok = TRUE;
 		GString *string;
+		cmde_ok = TRUE;
 
 		string = g_string_new (_("SQL statements:\n"
 					 "  they can span several lines, and are executed\n"
