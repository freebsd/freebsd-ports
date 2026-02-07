--- knightcap.c	Wed Mar 11 21:51:58 1998
+++ /home/andy/tmp/wrk/knightcap.c	Sun May 10 09:54:22 1998
@@ -934,7 +934,11 @@
 	reset_board();
 	init_movements();
 
+#ifdef __FreeBSD__
+	signal(SIGCHLD, SIG_IGN);
+#else
 	signal(SIGCLD, SIG_IGN);
+#endif
 
 	pid1 = getpid();
 
