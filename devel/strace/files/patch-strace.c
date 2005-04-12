--- strace.c.orig	Sun Dec 26 14:49:34 2004
+++ strace.c	Sun Dec 26 16:33:21 2004
@@ -539,6 +539,23 @@
 				cleanup();
 				exit(1);
 			}
+#ifdef FREEBSD
+			{
+				int status;
+				pid_t err;
+
+				do {
+					err = waitpid(pid, &status, WUNTRACED);
+				} while (err == -1 && errno == EINTR);
+				if (err == -1) {
+					fprintf(stderr,
+					        "waitpid() failed: %s\n",
+						strerror(errno));
+					cleanup();
+					exit(1);
+				}
+			}
+#endif
 #ifdef USE_PROCFS
 			if (proc_open(tcp, 0) < 0) {
 				fprintf(stderr, "trouble opening proc file\n");
