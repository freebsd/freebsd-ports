--- src/gui/glame_console.c.orig	2008-03-02 14:01:12.000000000 -0500
+++ src/gui/glame_console.c	2008-03-02 14:01:34.000000000 -0500
@@ -60,7 +60,7 @@ static void port_register()
 	port = scm_make_port_type("glame-console", NULL, port_write);
 
 	/* Create new port - shamelessly copied from libguile/strports.c */
-	GLAME_NEWCELL(s_port);
+	SCM_NEWCELL(s_port);
 	SCM_DEFER_INTS;
 	pt = scm_add_to_port_table(s_port);
 #ifdef SCM_SET_CELL_TYPE /* guile >= 1.4 */
