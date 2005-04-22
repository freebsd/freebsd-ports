--- src/fr-command-tar.c.orig	Fri Apr 22 13:11:56 2005
+++ src/fr-command-tar.c	Fri Apr 22 13:16:00 2005
@@ -221,6 +221,10 @@
 	if (g_file_test ("/usr/sfw/bin/gtar", G_FILE_TEST_IS_EXECUTABLE)) {
 		command = g_strdup ("/usr/sfw/bin/gtar");
 	}
+#elif defined(__FreeBSD__)
+	if (g_file_test ("%%LOCALBASE%%/bin/gtar", G_FILE_TEST_IS_EXECUTABLE)) {
+		command = g_strdup ("%%LOCALBASE%%/bin/gtar");
+	}
 #endif
 	if (command != NULL)
 		fr_process_begin_command (comm->process, command);
