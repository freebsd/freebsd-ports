--- strace.c.orig	2008-08-19 12:47:50.000000000 +0800
+++ strace.c	2008-11-20 22:48:39.000000000 +0800
@@ -604,6 +604,23 @@
 			cleanup();
 			exit(1);
 		}
+#ifdef FREEBSD
+		{
+			int status;
+			pid_t err;
+
+			do {
+				err = waitpid(pid, &status, WUNTRACED);
+			} while (err == -1 && errno == EINTR);
+			if (err == -1) {
+				fprintf(stderr,
+						"waitpid() failed: %s\n",
+					strerror(errno));
+				cleanup();
+				exit(1);
+			}
+		}
+#endif
 #ifdef USE_PROCFS
 		if (proc_open(tcp, 0) < 0) {
 			fprintf(stderr, "trouble opening proc file\n");
