--- src/syscall.c.orig	2015-06-04 17:20:18 UTC
+++ src/syscall.c
@@ -90,7 +90,7 @@ char	*argv[];
                     fprintf(stderr,"%s: fork failed\n", argv[0]);
                     exit(1);
                 } else if (pid == 0) {
-                    execl("/bin/true", (char *) 0);
+                    execl("/bin/true", (char *) 0, (char *) 0);
                     fprintf(stderr,"%s: exec /bin/true failed\n", argv[0]);
                     exit(1);
                 } else {
