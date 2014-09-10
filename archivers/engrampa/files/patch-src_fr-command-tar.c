--- src/fr-command-tar.c.orig	Sun Oct 15 12:33:56 2006
+++ src/fr-command-tar.c	Mon Oct 16 19:18:03 2006
@@ -231,6 +231,9 @@
 #if defined (__SVR4) && defined (__sun)
 	if (g_file_test ("/usr/sfw/bin/gtar", G_FILE_TEST_IS_EXECUTABLE))
 		command = g_strdup ("/usr/sfw/bin/gtar");
+#elif defined(__FreeBSD__)
+	if (g_file_test ("%%LOCALBASE%%/bin/gtar", G_FILE_TEST_IS_EXECUTABLE))
+		command = g_strdup ("%%LOCALBASE%%/bin/gtar");
 #endif
 	if (command != NULL)
 		fr_process_begin_command (comm->process, command);
