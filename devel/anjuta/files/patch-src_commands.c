--- src/commands.c.orig	Tue Aug 31 00:41:32 2004
+++ src/commands.c	Tue Aug 31 00:41:56 2004
@@ -102,6 +102,7 @@
 /* Ditto */
 static gchar *
 term_commands[] = {
+	"gnome-terminal -e '$(anjuta.current.command)'",
 	"gnome-terminal -e \"$(anjuta.current.command)\"",
 	"gnome-terminal -x sh -c \"$(anjuta.current.command)\"",
 	"gnome-terminal --command=\"sh -c \\\"$(anjuta.current.command); read x\\\"\"",
