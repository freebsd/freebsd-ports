--- mono/jit/jit.c.orig	Thu Dec 26 13:13:15 2002
+++ mono/jit/jit.c	Thu Dec 26 13:13:31 2002
@@ -4184,7 +4184,7 @@
 	sigemptyset (&sa.sa_mask);
 	sa.sa_flags = 0;
 	//g_assert (syscall (SYS_sigaction, SIGILL, &sa, NULL) != -1);
-	g_assert (sigaction (SIGRTMIN, &sa, NULL) != -1);
+	g_assert (sigaction (SIGUSR1, &sa, NULL) != -1);
 
 #if 1
 	/* catch SIGSEGV */
