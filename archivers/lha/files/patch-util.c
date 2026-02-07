--- src/util.c.orig	2000-10-04 14:57:38 UTC
+++ src/util.c
@@ -28,10 +28,10 @@ copyfile(f1, f2, size, crc_flg)	/* retur
 				 * append */
 {
 	unsigned short  xsize;
-	char           *buf;
+	unsigned char   *buf;
 	long            rsize = 0;
 
-	if ((buf = (char *) malloc(BUFFERSIZE)) == NULL)
+	if ((buf = (unsigned char *) malloc(BUFFERSIZE)) == NULL)
 		fatal_error("virtual memory exhausted.\n");
 	crc = 0;
 	if ((crc_flg == 2 || crc_flg) && text_mode)
@@ -100,9 +100,7 @@ encode_stored_crc(ifp, ofp, size, origin
 	erreturns *filename														*/
 /* ------------------------------------------------------------------------ */
 unsigned char  *
-convdelim(path, delim)
-	unsigned char  *path;
-	unsigned char   delim;
+convdelim(unsigned char *path, unsigned char delim)
 {
 	unsigned char   c;
 	unsigned char  *p;
@@ -276,21 +274,27 @@ rmdir(path)
 	char           *path;
 {
 	int             stat, rtn = 0;
-	char           *cmdname;
-	if ((cmdname = (char *) malloc(strlen(RMDIRPATH) + 1 + strlen(path) + 1))
-	    == 0)
+	pid_t           child;
+
+
+	/* XXX thomas: shell meta chars in path could exec commands */
+	/* therefore we should avoid using system() */
+	if ((child = fork()) < 0)
+		return (-1);    /* fork error */
+	else if (child) {       /* parent process */
+		while (child != wait(&stat))    /* ignore signals */
+			continue;
+	}
+	else {                  /* child process */
+		execl(RMDIRPATH, "rmdir", path, (char *) 0);
+		/* never come here except execl is error */
 		return (-1);
-	strcpy(cmdname, RMDIRPATH);
-	*(cmdname + strlen(RMDIRPATH)) = ' ';
-	strcpy(cmdname + strlen(RMDIRPATH) + 1, path);
-	if ((stat = system(cmdname)) < 0)
-		rtn = -1;	/* fork or exec error */
-	else if (stat) {	/* RMDIR command error */
-		errno = EIO;
-		rtn = -1;
 	}
-	free(cmdname);
-	return (rtn);
+	if (stat != 0) {
+		errno = EIO;    /* cannot get error num. */
+		return (-1);
+	}
+	return (0);
 }
 
 /* ------------------------------------------------------------------------ */
