--- src/execl.c.orig	Wed Jul 28 23:46:58 1999
+++ src/execl.c	Fri Mar 23 09:20:36 2007
@@ -88,7 +88,7 @@
 		fprintf(stderr, "%lu loops\n", iter);
 		exit(0);
 		}
-	execl(fullpath, fullpath, "0", dur_str, count_str, start_str, 0);
+	execl(fullpath, fullpath, "0", dur_str, count_str, start_str, NULL);
 	printf("Exec failed at iteration %lu\n", iter);
 	perror("Reason");
 	exit(1);
