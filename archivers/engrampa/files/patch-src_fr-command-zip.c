--- src/fr-command-zip.c.orig	2015-10-14 17:33:41 UTC
+++ src/fr-command-zip.c
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
 	fr_process_add_arg (comm->process, "--");
@@ -307,7 +311,11 @@ fr_command_zip_extract (FrCommand  *comm
 				      process_line__common,
 				      comm);
 
+#ifdef __FreeBSD__
+	fr_process_begin_command (comm->process, "%%LOCALBASE%%/bin/unzip");
+#else
 	fr_process_begin_command (comm->process, "unzip");
+#endif
 
 	if (dest_dir != NULL) {
 		fr_process_add_arg (comm->process, "-d");
@@ -341,7 +349,11 @@ fr_command_zip_extract (FrCommand  *comm
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
 	fr_process_add_arg (comm->process, "--");
