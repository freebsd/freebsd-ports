--- tools/gda-config-tool.c.orig	Fri Jul 26 16:19:17 2002
+++ tools/gda-config-tool.c	Fri Jul 26 16:18:47 2002
@@ -1136,7 +1136,7 @@
 static char **
 completion_func (const gchar *text, int start, int end)
 {
-	return ((start == 0) ? rl_completion_matches (text, cmd_generator) :
+	return ((start == 0) ? completion_matches (text, cmd_generator) :
 				NULL);
 }
 
