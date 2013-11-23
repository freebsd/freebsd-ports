--- src/fr-command-zip.c.orig	2010-01-02 17:02:44.000000000 -0500
+++ src/fr-command-zip.c	2010-01-02 17:08:03.000000000 -0500
@@ -187,7 +187,11 @@ fr_command_zip_list (FrCommand  *comm)
 {
 	fr_process_set_out_line_func (comm->process, list__process_line, comm);
 
+#ifdef __FreeBSD__
+	fr_process_begin_command (comm->process, "%%LOCALBASE%%/bin/unzip");
+#else
 	fr_process_begin_command (comm->process, "unzip");
+#endif
 	fr_process_set_begin_func (comm->process, list__begin, comm);
 	fr_process_add_arg (comm->process, "-ZTs");
 	fr_process_add_arg (comm->process, comm->filename);
@@ -302,7 +306,11 @@ fr_command_zip_extract (FrCommand  *comm
 				      process_line__common,
 				      comm);
 
+#ifdef __FreeBSD__
+	fr_process_begin_command (comm->process, "%%LOCALBASE%%/bin/unzip");
+#else
 	fr_process_begin_command (comm->process, "unzip");
+#endif
 
 	if (dest_dir != NULL) {
 		fr_process_add_arg (comm->process, "-d");
@@ -334,7 +342,11 @@ fr_command_zip_extract (FrCommand  *comm
 static void
 fr_command_zip_test (FrCommand   *comm)
 {
-	fr_process_begin_command (comm->process, "unzip");
+#ifdef __FreeBSD__
+	fr_process_begin_command (comm->process, "%%LOCALBASE%%/bin/unzip");
+#else
+	fr_process_begin_command (comm->process, "%%LOCALBASE%%/bin/unzip");
+#endif
 	fr_process_add_arg (comm->process, "-t");
 	add_password_arg (comm, comm->password);
 	fr_process_add_arg (comm->process, comm->filename);
