--- src/exec.c.orig	2020-10-05 09:17:52 UTC
+++ src/exec.c
@@ -55,7 +55,7 @@ static	sighandler_t oldsigtstp; /* old value of SIGTST
 
 #ifndef __MSDOS__ /* none of these is needed, there */
 static	int	join(pid_t p);
-static	int	myexecvp(char *a, char **args);
+void		myexecvp(char *a, char **args);
 static	pid_t	myfork(void);
 #endif
 
@@ -111,7 +111,7 @@ execute(char *a, ...)	/* note: "exec" is already defin
 /* myexecvp is an interface to the execvp system call to
  * modify argv[0] to reference the last component of its path-name.
  */
-static int
+void
 myexecvp(char *a, char **args)
 {
     char    msg[MSGLEN + 1];
