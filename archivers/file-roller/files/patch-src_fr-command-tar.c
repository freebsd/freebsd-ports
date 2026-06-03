--- src/fr-command-tar.c.orig	2025-10-19 06:50:04 UTC
+++ src/fr-command-tar.c
@@ -275,8 +275,6 @@ fr_command_tar_list (FrCommand *comm)
 	fr_process_set_out_line_func (comm->process, process_line, comm);
 
 	begin_tar_command (comm);
-	fr_process_add_arg (comm->process, "--force-local");
-	fr_process_add_arg (comm->process, "--no-wildcards");
 	fr_process_add_arg (comm->process, "-tvf");
 	fr_process_add_arg (comm->process, comm->filename);
 	add_compress_arg (comm);
@@ -345,9 +343,6 @@ fr_command_tar_add (FrCommand  *comm,
 				      comm);
 
 	begin_tar_command (comm);
-	fr_process_add_arg (comm->process, "--force-local");
-	fr_process_add_arg (comm->process, "--no-recursion");
-	fr_process_add_arg (comm->process, "--no-wildcards");
 	fr_process_add_arg (comm->process, "-v");
 	fr_process_add_arg (comm->process, "-p");
 	if (follow_links)
@@ -419,8 +414,6 @@ fr_command_tar_delete (FrCommand  *comm,
 
 	begin_tar_command (comm);
 	fr_process_set_begin_func (comm->process, begin_func__delete, comm);
-	fr_process_add_arg (comm->process, "--force-local");
-	fr_process_add_arg (comm->process, "--no-wildcards");
 	fr_process_add_arg (comm->process, "-v");
 	fr_process_add_arg (comm->process, "--delete");
 	fr_process_add_arg (comm->process, "-f");
@@ -466,8 +459,6 @@ fr_command_tar_extract (FrCommand  *comm,
 				      comm);
 
 	begin_tar_command (comm);
-	fr_process_add_arg (comm->process, "--force-local");
-	fr_process_add_arg (comm->process, "--no-wildcards");
 	fr_process_add_arg (comm->process, "-v");
 	fr_process_add_arg (comm->process, "-p");
 
