--- console.c.orig	Sun Aug 14 09:38:36 2005
+++ console.c	Mon Jan 16 18:54:47 2006
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
