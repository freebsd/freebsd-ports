--- src/execl.c.orig	1999-07-28 21:46:58 UTC
+++ src/execl.c
@@ -88,7 +88,7 @@ char	*argv[];
 		fprintf(stderr, "%lu loops\n", iter);
 		exit(0);
 		}
-	execl(fullpath, fullpath, "0", dur_str, count_str, start_str, 0);
+	execl(fullpath, fullpath, "0", dur_str, count_str, start_str, NULL);
 	printf("Exec failed at iteration %lu\n", iter);
 	perror("Reason");
 	exit(1);
