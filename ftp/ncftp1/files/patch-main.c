--- main.c.orig	1995-10-29 22:17:55.000000000 -0500
+++ main.c	2014-08-06 20:07:56.000000000 -0400
@@ -69,7 +69,7 @@
 string				pager;				/* program to browse text files */
 string				version = FTP_VERSION;
 long				eventnumber;		/* number of commands we've done */
-FILE				*logf = NULL;		/* log user activity */
+FILE				*logfile = NULL;		/* log user activity */
 longstring			logfname;			/* name of the logfile */
 long				logsize = 4096L;	/* max log size. 0 == no limit */
 int					percent_flags;		/* "%" in prompt string? */
@@ -200,7 +200,7 @@
 	ansi_escapes = 0;
 	if ((cp = getenv("TERM")) != NULL) {
 		if ((*cp == 'v' && cp[1] == 't')		/* vt100, vt102, ... */
-			|| (strcmp(cp, "xterm") == 0))
+			|| (strncmp(cp, "xterm", 5) == 0))
 			ansi_escapes = 1;
 	}
 #endif
@@ -334,7 +334,7 @@
 	cpend = 0;  /* no pending replies */
 	
 	if (*logfname)
-		logf = fopen (logfname, "a");
+		logfile = fopen (logfname, "a");
 
 
 	/* The user specified a host, maybe in 'colon-mode', on the command
