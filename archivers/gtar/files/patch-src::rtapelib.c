
$FreeBSD$

--- src/rtapelib.c	2002/06/01 21:08:46	1.1
+++ src/rtapelib.c	2002/06/01 21:09:16
@@ -437,6 +437,9 @@
     /* Identify the remote command to be executed.  */
 
     if (!remote_shell)
+      remote_shell = getenv("TAR_RSH");
+
+    if (!remote_shell)
       {
 #ifdef REMOTE_SHELL
 	remote_shell = REMOTE_SHELL;
@@ -488,10 +491,10 @@
 #endif
 
 	if (remote_user)
-	  execl (remote_shell, remote_shell_basename, remote_host,
-		 "-l", remote_user, "/etc/rmt", (char *) 0);
+	  execlp (remote_shell, remote_shell_basename, "-l", remote_user,
+	  	remote_host, "/etc/rmt", (char *) 0);
 	else
-	  execl (remote_shell, remote_shell_basename, remote_host,
+	  execlp (remote_shell, remote_shell_basename, remote_host,
 		 "/etc/rmt", (char *) 0);
 
 	/* Bad problems if we get here.  */
