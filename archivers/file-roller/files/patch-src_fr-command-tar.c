--- src/fr-command-tar.c.orig	Fri Jul  1 14:41:32 2005
+++ src/fr-command-tar.c	Sun Jul  3 19:03:01 2005
@@ -222,6 +223,10 @@ begin_tar_command (FRCommand *comm)
 #if defined (__SVR4) && defined (__sun)
 	if (g_file_test ("/usr/sfw/bin/gtar", G_FILE_TEST_IS_EXECUTABLE)) {
 		command = g_strdup ("/usr/sfw/bin/gtar");
+	}
+#elif defined(__FreeBSD__)
+	if (g_file_test ("%%LOCALBASE%%/bin/gtar", G_FILE_TEST_IS_EXECUTABLE)) {
+		command = g_strdup ("%%LOCALBASE%%/bin/gtar");
 	}
 #endif
 	if (command != NULL)
