--- src/fr-command-tar.c.orig	2014-08-13 05:21:20 UTC
+++ src/fr-command-tar.c
@@ -236,6 +236,9 @@ begin_tar_command (FrCommand *comm)
 #if defined (__SVR4) && defined (__sun)
 	if (g_file_test ("/usr/sfw/bin/gtar", G_FILE_TEST_IS_EXECUTABLE))
 		command = g_strdup ("/usr/sfw/bin/gtar");
+#elif defined(__FreeBSD__)
+	if (g_file_test ("%%LOCALBASE%%/bin/gtar", G_FILE_TEST_IS_EXECUTABLE))
+		command = g_strdup ("%%LOCALBASE%%/bin/gtar");
 #endif
 	if (command != NULL)
 		fr_process_begin_command (comm->process, command);
