--- src/term.c.orig	1997-01-25 00:03:58.000000000 +0900
+++ src/term.c	2012-05-10 00:17:11.736555617 +0900
@@ -33,7 +33,13 @@
 #include	<termio.h>
 #elif defined(__FreeBSD__)
 #include	<termios.h>
-#include	<machine/console.h>
+#include        <osreldate.h>
+#if __FreeBSD_version >= 410000
+#  include      <sys/consio.h>
+#  include      <sys/kbio.h>
+#else
+#  include      <machine/console.h>
+#endif
 #define termio termios
 #endif
 #include	<signal.h>
@@ -70,12 +76,15 @@
 
 int	masterPty;			 /* master pseudo-tty file descriptor */
 
-#define	MAX_TTYNAME	10
+#define	MAX_TTYNAME	20
 
 static int	childPid, sockFd, slavePty;
 static struct termio	oldTio;
 static char	ptyName[MAX_TTYNAME + 1];
 static int orgVtNum = -1;
+#if defined(__FreeBSD__)
+static int exec_mode = 0;
+#endif
 
 struct initInfo {
     bool display;			 /* display initialized */
@@ -129,8 +138,13 @@
     if (WEXITSTATUS(stat) & 0x7f)
 	if (WIFSIGNALED(stat))
 	    fatal("child died with signal -- %s\r\n", sys_siglist[WTERMSIG(stat)]);
-	else
+	else {
+#if defined(__FreeBSD__)
+	    if (exec_mode)	/* reflect  exit code */
+	    	exit(WEXITSTATUS(stat) & 0x7f);
+#endif
 	    fatal("child exited with status %d\r\n", WEXITSTATUS(stat) & 0x7f);
+	}
     else if (signum == SIGHUP) {
 	fprintf(stderr, "\r\nKON> switched to new VC\r\n");
 	exit(EXIT_SUCCESS);
@@ -201,11 +215,15 @@
 	}
 	if (FD_ISSET(0, &readFds)) {
 	    i = read(0, buff, BUFSIZ);
+#if defined(__FreeBSD__)
+	    if (strncmp(getenv("TERM"), "vt100", 5) == 0)
+		i = cons25tovt100(buff, i, BUFSIZ);
+#endif
 	    if (i > 0) write(masterPty, buff, i);
 	    PollCursor(TRUE);
 	}
 	if (FD_ISSET(sockFd, &readFds)) SocketInterface(sockFd);
-	if (mInfo.has_mouse) {
+	if (mInfo.has_mouse && mouseFd > 0) {
 	    if (FD_ISSET(mouseFd, &readFds) && con.active) {
 		i = read(mouseFd, buff, BUFSIZ);
 		if (i > 0) MouseGetPacket(buff, i);
@@ -215,6 +233,27 @@
     }
 }
 
+#if defined(__FreeBSD__)
+/*
+ *	'e', 's', 'u' 以外の文字がないかチェックする
+ */
+static int Check_esu(char *p)
+{
+    for (; *p; ++p) {
+	switch (*p) {
+	case 'e':
+	    return(1);
+	case 's':
+	case 'u':
+	    continue;
+	default:
+	    return(0);
+	}
+    }
+    return(1);
+}
+#endif
+
 static void	ProcessArgs(int argc, const char *argv[])
 {
     int	i = 0;
@@ -226,13 +265,55 @@
     }
     ConsoleInit(video);
     while (i < argc) {
-	const char	*arg;
+	const char	*arg = argv[i];
+
+#if defined(__FreeBSD__)
+	if (argv[i][0] == '-' && Check_esu(&argv[i][1])) {
+	    char *p;
 
-	if (argv[i][0] != '-') {
-	    warn("bad arg `%s'; assumed `-%s'\r\n", argv[i]);
-	    arg = (char *) argv[i];
-	} else
-	    arg = (char *) argv[i] + 1;
+	    for (p = &argv[i][1]; *p; ++p) {
+		if (*p == 'e') {
+		    ConfigExecProg(&argv[i+1]);
+		    ConfigMessage("Off");
+		    exec_mode = 1;
+		    return;
+		}
+		else if (*p == 's')		/* single user mode */
+		    UnUseUtmp(1);
+		else if (*p == 'u') {		/* unset TERM mode */
+		    ConfigUnsetTerm(1);
+		}
+	    }
+	}
+	else {
+	    if (*arg != '-')
+		warn("bad arg `%s'; assumed `-%s'\n", arg, arg);
+	    else
+		++arg;
+	    if (!strcasecmp(arg, "help")) {
+		message("Usage: kon2 [video] [-option value] ...\n");
+		exit(EXIT_FAILURE);
+	    }
+	    i++;
+	    if (i >= argc) {
+		error("no value for `%s'\r\n", arg);
+		break;
+	    }
+	    if (!strcasecmp(arg, "e"))
+		ConfigExecProg(argv[i]);
+	    else if (SetCapArg(arg, argv[i]) < 0)
+		warn("invalid capability `%s' ignored\r\n", arg);
+	}
+	i++;
+#else
+	if (*arg != '-')
+	    warn("bad arg `%s'; assumed `-%s'\n", arg, arg);
+	else
+	    ++arg;
+	if (!strcasecmp(arg, "help")) {
+	    message("Usage: kon2 [video] [-option value] ...\n");
+	    exit(EXIT_FAILURE);
+	}
 	i++;
 	if (i >= argc) {
 	    error("no value for `%s'\r\n", arg);
@@ -243,12 +324,32 @@
 	else if (SetCapArg(arg, argv[i]) < 0)
 	    warn("invalid capability `%s' ignored\r\n", arg);
 	i++;
+#endif
     }
 }
 
 static int	savedArgc;		 /* argc of startup time */
 static const char	**savedArgv;	 /* argv of startup time */
 
+static int ttyNumber = 0;
+
+int
+set_vt_number(void)
+{
+#if defined(__FreeBSD__)
+    ttyNumber = strtol(ttyname(0) + 9, NULL, 16);
+#elif defined(linux)
+    ttyNumber = atoi(ttyname(0) + 8);
+#endif	/* linux */
+    return ttyNumber;
+}
+
+int
+TermGetNumber(void)
+{
+    return ttyNumber;
+}
+
 /* Do initialization before reading config file */
 void	TermInit(int argc, const char *argv[])
 {
@@ -257,6 +358,7 @@
     init.display = init.utmp = init.socket = init.termio = FALSE;
     /* Initialize subsystems. */
     
+    set_vt_number();
     CapInit();
     ChildInit();
     MouseInit();
@@ -346,8 +448,8 @@
 	mouseFd = MouseStart();
     }
 
-    chown("/dev/tty0", getuid(), getgid());
 #if defined(linux)
+    chown("/dev/tty0", getuid(), getgid());
     sockFd = SocketInit(ttyname(0) + 8);
 #elif defined(__FreeBSD__)
     sockFd = SocketInit(ttyname(0) + 9);
@@ -372,6 +474,7 @@
 
 	/* Signal Setting */
 	signal(SIGCHLD, ExitPty);
+	signal(SIGPIPE, SIG_IGN);
 	signal(SIGHUP, ExitTerm);
 	signal(SIGTERM, ExitTerm);
 	signal(SIGSEGV, ExitTerm);
@@ -449,11 +552,13 @@
 	PerrorExit("/dev/console");
     }
 #elif defined(__FreeBSD__)
-    cfd = open("/dev/vga", O_WRONLY);
-    if (cfd < 0 && (cfd = open("/dev/vga", O_RDONLY)) < 0) {
-	PerrorExit("/dev/vga");
+    cfd = open("/dev/vga", O_RDONLY);
+    if (cfd == -1) {
+	cfd = open("/dev/console", O_RDONLY);
+	if (cfd == -1)
+	    PerrorExit("/dev/console");
     }
-#endif
+#endif	/* __FreeBSD__ */
     ioctl(cfd, VT_ACTIVATE, orgVtNum);
     close(cfd);
 }
@@ -470,22 +575,36 @@
     cfd = open("/dev/console", O_WRONLY);
     if (cfd < 0 && (cfd = open("/dev/console", O_RDONLY)) < 0)
 	fatal("can't open /dev/console");
-#elif defined(__FreeBSD__)
-    cfd = open("/dev/vga", O_WRONLY);
-    if (cfd < 0 && (cfd = open("/dev/vga", O_RDONLY)) < 0)
-	fatal("can't open /dev/vga");
-#endif
+
     ioctl(cfd, KDGETMODE, &mode);
     if (mode == KD_TEXT) {
 	close(cfd);
 	return;
     }
-#if defined(linux)
     ioctl(cfd, VT_GETSTATE, &vts);
     orgVtNum = vts.v_active;
-#endif
-    ioctl(cfd, VT_OPENQRY, &vtNum);
-    if (vtNum < 0)
+
+#elif defined(__FreeBSD__)
+    /* check for syscons mode */
+    if (ioctl(0, KDGETMODE, &mode) == -1)
+        fatal("KON is require the syscons(4)");
+    else if (mode != KD_TEXT)
+	fatal("unknown terminal mode.");
+    else if (strcmp(ttyname(0), "/dev/console") != 0)
+	return;
+
+    cfd = open("/dev/vga", O_RDONLY);
+    if (cfd == -1) {
+	cfd = open("/dev/console", O_RDONLY);
+	if (cfd == -1)
+	    fatal("can't open /dev/console");
+    }
+    if (ioctl(cfd, VT_GETINDEX, &orgVtNum) == -1)
+	fatal("ioctl(VT_GETINDEX)");
+#endif /* __FreeBSD__ */
+
+    errno = 0;
+    if (ioctl(cfd, VT_OPENQRY, &vtNum) == -1 || vtNum < 0)
 	fatal("can't get free VC");
     parent = getpid();
     if ((child = fork()) == -1)
@@ -493,12 +612,13 @@
     if (child) {
 	signal(SIGHUP, ExitPty);
 	pause();
+	fatal("internal error.");
     }
     setsid();
 #if defined(linux)
     sprintf(vtty, "/dev/tty%d", vtNum);
 #elif defined(__FreeBSD__)
-    sprintf(vtty, "/dev/ttyv%d", vtNum);
+    sprintf(vtty, "/dev/ttyv%d", vtNum - 1);
 #endif
     if ((vfd = open(vtty, O_RDWR)) < 0)
 	fatal("can't open %s", vtty);
@@ -509,5 +629,6 @@
     dup2(vfd, 0);
     dup2(vfd, 1);
     dup2(vfd, 2);
+    close(vfd);
     kill(parent, SIGHUP);
 }
