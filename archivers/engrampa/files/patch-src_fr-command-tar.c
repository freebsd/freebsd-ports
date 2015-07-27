--- src/fr-command-tar.c.orig	2014-11-19 15:44:09.000000000 +0100
+++ src/fr-command-tar.c	2014-12-04 18:28:31.998497849 +0100
@@ -245,6 +245,10 @@
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
