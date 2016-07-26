--- src/gui/glame_console.c.orig	2004-10-23 13:09:24 UTC
+++ src/gui/glame_console.c
@@ -60,7 +60,7 @@ static void port_register()
 	port = scm_make_port_type("glame-console", NULL, port_write);
 
 	/* Create new port - shamelessly copied from libguile/strports.c */
-	GLAME_NEWCELL(s_port);
+	SCM_NEWCELL(s_port);
 	SCM_DEFER_INTS;
 	pt = scm_add_to_port_table(s_port);
 #ifdef SCM_SET_CELL_TYPE /* guile >= 1.4 */
