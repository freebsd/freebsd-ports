--- src/fr-command-zip.c.orig	2015-02-15 10:13:10 UTC
+++ src/fr-command-zip.c
@@ -179,7 +179,11 @@ fr_command_zip_list (FrCommand  *comm)
 {
 	fr_process_set_out_line_func (comm->process, list__process_line, comm);
 
+#ifdef __FreeBSD__
+	fr_process_begin_command (comm->process, "%%LOCALBASE%%/bin/unzip");
+#else
 	fr_process_begin_command (comm->process, "unzip");
+#endif
 	fr_process_set_begin_func (comm->process, list__begin, comm);
 	fr_process_add_arg (comm->process, "-ZTs");
 	fr_process_add_arg (comm->process, "--");
@@ -299,7 +303,11 @@ fr_command_zip_extract (FrCommand  *comm
 				      process_line__common,
 				      comm);
 
+#ifdef __FreeBSD__
+	fr_process_begin_command (comm->process, "%%LOCALBASE%%/bin/unzip");
+#else
 	fr_process_begin_command (comm->process, "unzip");
+#endif
 
 	if (dest_dir != NULL) {
 		fr_process_add_arg (comm->process, "-d");
@@ -333,7 +341,11 @@ fr_command_zip_extract (FrCommand  *comm
 static void
 fr_command_zip_test (FrCommand   *comm)
 {
+#ifdef __FreeBSD__
+	fr_process_begin_command (comm->process, "%%LOCALBASE%%/bin/unzip");
+#else
 	fr_process_begin_command (comm->process, "unzip");
+#endif
 	fr_process_add_arg (comm->process, "-t");
 	add_password_arg (comm, FR_ARCHIVE (comm)->password);
 	fr_process_add_arg (comm->process, "--");
