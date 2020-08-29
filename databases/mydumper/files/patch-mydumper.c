--- mydumper.c.orig	2017-09-07 14:53:02 UTC
+++ mydumper.c
@@ -824,7 +824,7 @@ int main(int argc, char *argv[])
 	g_option_context_free(context);
 
 	if (program_version) {
-		g_print("mydumper %s, built against MySQL %s\n", VERSION, MYSQL_SERVER_VERSION);
+		g_print("mydumper %s, built against MySQL %s\n", VERSION, MYSQL_VERSION_STR);
 		exit (EXIT_SUCCESS);
 	}
 
