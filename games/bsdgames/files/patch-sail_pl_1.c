--- ./sail/pl_1.c
+++ ./sail/pl_1.c
@@ -122,7 +122,11 @@ choke(void)
 void
 child(void)
 {
+#ifdef __DragonFly__
 	union wait status;
+#else
+	int status;
+#endif
 	int pid;
 
 	signal(SIGCHLD, SIG_IGN);
