
$FreeBSD$

--- src/libsoup/soup-socket.c	2001/09/28 12:13:58	1.1
+++ src/libsoup/soup-socket.c	2001/09/28 09:15:15
@@ -783,7 +783,7 @@
 
 		signal (SIGCHLD, SIG_IGN);
 
-		if (ptrace (PTRACE_ATTACH, getppid (), NULL, NULL) == -1) {
+		if (ptrace (PT_ATTACH, getppid (), NULL, 0) == -1) {
 			/* 
 			 * Attach failed; it's probably already being
 			 * debugged. 
@@ -800,7 +800,7 @@
 		 */
 		waitpid (getppid (), NULL, 0);
 
-		if (ptrace (PTRACE_DETACH, getppid (), NULL, NULL) == -1)
+		if (ptrace (PT_DETACH, getppid (), NULL, 0) == -1)
 			g_warning ("ptrace: Detach failed: %s", 
 				   strerror(errno));
 
