--- src/ghtml.c.orig	Sat May 22 09:16:50 2004
+++ src/ghtml.c	Thu Jul  8 00:16:27 2004
@@ -169,8 +169,9 @@
 			type = SCM_CDR (node);
 			if (SCM_SYMBOLP(type) || SCM_STRINGP (type))
 			{
+				char *buff;
 				cur_type = GTT_NONE;
-				char *buff = SCM_STRING_CHARS (type);
+				buff = SCM_STRING_CHARS (type);
 
 				if ((!strncmp (buff, "gtt-project-ptr",15)) ||
 				    (!strncmp (buff, "gtt-project-list",16)))
@@ -1271,6 +1272,9 @@
 static SCM 
 my_catch_handler (void *data, SCM tag, SCM throw_args)
 {
+	SCM fmt;
+	SCM s_str;
+
 	printf ("Error: GnoTime caught error during scheme parse\n");
 	if (SCM_SYMBOLP(tag))
 	{
@@ -1279,8 +1283,8 @@
 	}
 	scm_backtrace(); 
 
-	SCM fmt = scm_makfrom0str ("~S");
-	SCM s_str = scm_simple_format (SCM_BOOL_F, fmt, SCM_LIST1(throw_args));
+	fmt = scm_makfrom0str ("~S");
+	s_str = scm_simple_format (SCM_BOOL_F, fmt, SCM_LIST1(throw_args));
 	printf ("\tthrow_args=%s\n", SCM_STRING_CHARS (s_str));
 
 	return SCM_EOL;
@@ -1297,8 +1301,9 @@
 	/* no-op for now, just copy it into the window  */
 	if (ghtml->write_stream)
 	{
+		size_t nr;
 		(ghtml->write_stream) (ghtml, "<link", 5, ghtml->user_data);
-		size_t nr = strlen (str);
+		nr = strlen (str);
 		(ghtml->write_stream) (ghtml, str, nr, ghtml->user_data);
 		(ghtml->write_stream) (ghtml, ">", 1, ghtml->user_data);
 	}
@@ -1313,6 +1318,8 @@
 	GString *template;
 	char *start, *end, *scmstart, *comstart, *linkstart;
 	size_t nr;
+	GnomeVFSResult    result;
+	GnomeVFSHandle   *handle;
 
 	if (!ghtml) return;
 	if (prj) ghtml->prj = prj;
@@ -1327,8 +1334,6 @@
 	}
 
 	/* Try to get the ghtml file ... */
-	GnomeVFSResult    result;
-	GnomeVFSHandle   *handle;
 	result = gnome_vfs_open (&handle, filepath, GNOME_VFS_OPEN_READ);
 	if ((GNOME_VFS_OK != result) && (0==ghtml->open_count))
 	{
