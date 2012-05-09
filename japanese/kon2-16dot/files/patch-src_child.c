--- src/child.c.orig	1997-01-24 09:36:14.000000000 +0900
+++ src/child.c	2012-05-10 00:17:11.718554719 +0900
@@ -31,6 +31,7 @@
 #include	<unistd.h>
 #ifdef __FreeBSD__
 #include        <errno.h>
+#include        <sys/ioctl.h>
 #endif
 
 #include	<getcap.h>
@@ -39,16 +40,41 @@
 #include	<version.h>
 #include	<vc.h>
 
-static char *startupStr, *execProg;
+#if defined(__FreeBSD__)
+static char *startupStr = NULL, *execProg = NULL, **execArgv = NULL;
+
+int	ConfigExecProg(const char **argv)
+{
+	execArgv = argv;
+	SafeFree(execProg);
+	execProg = strdup(*argv);
+	return SUCCESS;
+}
+#else
+
+static char *startupStr = NULL, *execProg = NULL;
 
 int	ConfigExecProg(const char *string)
 {
+	SafeFree(execProg);
 	execProg = strdup(string);
 	return SUCCESS;
 }
+#endif
+
+#if defined(__FreeBSD__)
+static int unset_mode = 0;	/* TERM を変更しない */
+static int vt100_mode = 0;	/* vt100 または vt100-XXX */
+
+int	ConfigUnsetTerm(const int flag)
+{
+	unset_mode = flag;
+}
+#endif
 
 static int	ConfigStartup(const char *string)
 {
+	SafeFree(startupStr);
 	startupStr = strdup(string);
 	return SUCCESS;
 }
@@ -66,7 +92,11 @@
 
 static bool startupMessage;
 
+#if defined(__FreeBSD__)
+int	ConfigMessage(const char *confstr)
+#else
 static int	ConfigMessage(const char *confstr)
+#endif
 {
 	startupMessage = BoolConf(confstr);
 	return SUCCESS;
@@ -80,13 +110,17 @@
 
 void	ChildCleanup(void)
 {
-	free(startupStr);
+	SafeFree(startupStr);
+	SafeFree(execProg);
 }
 
 void	ChildStart(FILE *errfp)
 {
 	char	*shell, *tail, *tcap;
 	char	buff[80];
+#if defined(__FreeBSD__)
+	struct winsize win;
+#endif
 
 	setgid(getgid());
 	setuid(getuid());
@@ -96,43 +130,64 @@
 #if defined(linux)
 	sprintf(buff, "TERMCAP=:co#%d:li#%d:tc=console:",
 		dInfo.txmax + 1, dInfo.tymax + 1);
-#elif defined(__FreeBSD__)
-	sprintf(buff,"TERM=vt100");
-#endif
 
 	tcap = strdup(buff);
 	putenv(tcap);
+#elif defined(__FreeBSD__)
+	if (unset_mode) {
+	    if (strncmp(getenv("TERM"), "vt100", 5) == 0) {
+	    	vt100_mode = 1;
+	    	unset_mode = 0;
+	    }
+	}
+	else {
+	    putenv("TERM=vt100");
+	    vt100_mode = 1;
+	}
+	if (vt100_mode) {
+	    win.ws_row = dInfo.tymax + 1;
+	    win.ws_col = dInfo.txmax + 1;
+	    win.ws_xpixel = win.ws_ypixel = 0;
+	    ioctl(STDIN_FILENO, TIOCSWINSZ, &win);
+	}
+#endif
 
-	if (startupMessage)
+	if (startupMessage) {
 	    printf("\rKON2 Kanji On Console " VERSION
-		   " using VT number %c\r\n"
+		   " using VT number %d\n"
 		   "%*s\r\n"
-		   "%*s\r\n", *(ttyname(fileno(errfp))+8),
+		   "%*s\r\n",
+		   TermGetNumber(),
 		   dInfo.txmax,
 		   "Copyright (C) "
 		   "1993-1996  Takashi MANABE",
 		   dInfo.txmax,
 		   "1993, 1994 MAEDA Atusi   ");
 #if defined(__FreeBSD__)
-	printf("\rKON for FreeBSD-2.x ver0.01 Takashi OGURA\r\n");
+	    printf("\rKON for FreeBSD-2.x ver0.01 Takashi OGURA\r\n");
 #endif
-
+	}
 
 /*
-	printf("KON using VT number %c.\n\n",
-	       *(ttyname(fileno(errfp))+8));
+	printf("KON using VT number %d.\n\n", TermGetNumber());
 */
 	fflush(stdout);
 
 	if (execProg)
+#if defined(__FreeBSD__)
+	    execvp(execProg, execArgv);
+#else
 	    execlp(execProg, execProg, 0);
+#endif
 	else {
+	    char *ptr;
 	    if ((execProg = getenv("SHELL")) == NULL)
 		execProg = "/bin/sh";
 	    if ((tail = rindex(execProg, '/')) == NULL)
 		tail = " sh";
-	    sprintf(buff, "-%s", tail + 1);
-	    execl(execProg, buff, 0);
+	    ptr = strdup(tail);
+	    *ptr = '-';
+	    execl(execProg, ptr, 0);
 	}
 	fprintf(errfp, "KON> couldn't exec shell\r\n");
 	fprintf(errfp, "%s: %s\r\n", execProg, strerror(errno));
