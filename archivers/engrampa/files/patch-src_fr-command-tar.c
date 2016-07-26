--- src/fr-command-tar.c.orig	2015-10-14 17:33:41 UTC
+++ src/fr-command-tar.c
@@ -245,6 +245,10 @@ begin_tar_command (FrCommand *comm)
 		g_free (command);
 		command = g_strdup ("/usr/sfw/bin/gtar");
 	}
+#elif defined(__FreeBSD__)
+	if (g_file_test ("%%LOCALBASE%%/bin/gtar", G_FILE_TEST_IS_EXECUTABLE))
+		command = g_strdup ("%%LOCALBASE%%/bin/gtar");
+
 #endif
 	if (command != NULL)
 		fr_process_begin_command (comm->process, command);
