--- tests/coding-test.c.orig	2012-06-29 12:07:41.000000000 +0200
+++ tests/coding-test.c	2012-06-29 12:47:16.000000000 +0200
@@ -66,7 +66,7 @@
 			}
 		}
 		if (file_path && encoding) {
-			file = g_strdup_printf (file_path, path);
+			file = g_strdup_printf ("%s", path);
 			if (g_file_test (file, G_FILE_TEST_EXISTS)) {
 				soup_message_headers_append (msg->response_headers,
 							     "Content-Encoding",
