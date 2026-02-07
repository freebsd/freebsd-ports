--- ./console.c.orig	Sun Jan  8 18:27:46 2006
+++ ./console.c	Sat May 20 10:00:24 2006
@@ -205,8 +205,11 @@
 */
 void Con_Init (void)
 {
+	char	qclog_path[MAX_OSPATH];
+
+	snprintf(qclog_path, sizeof(qclog_path), "%s/qconsole.log", com_gamedir);
 	if (COM_CheckParm("-condebug"))
-		qconsole_log = fopen (va("%s/joequake/qconsole.log", com_basedir), "a");
+		qconsole_log = fopen (qclog_path, "a");
 
 	con_text = Hunk_AllocName (CON_TEXTSIZE, "context");
 	memset (con_text, ' ', CON_TEXTSIZE);
