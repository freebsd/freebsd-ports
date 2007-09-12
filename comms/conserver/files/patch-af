--- etc/console/console.m.orig	2000-08-02 11:39:42.000000000 -0700
+++ etc/console/console.m	2007-09-12 09:30:56.000000000 -0700
@@ -582,17 +582,17 @@
 		return;
 
 #if USE_TERMIOS
-	if (0 != ioctl(0, TCGETS, & o_tios)) {
+	if (0 != tcgetattr(0, & o_tios)) {
 		fprintf(stderr, "%s: iotcl: getsw: %s\n", progname, strerror(errno));
 		exit(10);
 	}
 	n_tios = o_tios;
-	n_tios.c_iflag &= ~(INLCR|IGNCR|ICRNL|IUCLC|IXON);
+	n_tios.c_iflag &= ~(INLCR|IGNCR|ICRNL|IXON);
 	n_tios.c_oflag &= ~OPOST;
 	n_tios.c_lflag &= ~(ICANON|ISIG|ECHO);
 	n_tios.c_cc[VMIN] = 1;
 	n_tios.c_cc[VTIME] = 0;
-	if (0 != ioctl(0, TCSETS, & n_tios)) {
+	if (0 != tcsetattr(0, TCSANOW, & n_tios)) {
 		fprintf(stderr, "%s: getarrt: %s\n", progname, strerror(errno));
 		exit(10);
 	}
@@ -668,7 +668,7 @@
 	if (!screwy)
 		return;
 #if USE_TERMIOS
-	(void)ioctl(0, TCSETS, (char *)&o_tios);
+	(void)tcsetattr(0, TCSANOW, &o_tios);
 #else
 #if USE_TERMIO
 	(void)ioctl(0, TCSETA, (char *)&o_tio);
@@ -693,7 +693,7 @@
 	register int nr;
 
 	while (0 != iLen) {
-		if (-1 == (nr = write(fd, pcBuf, iLen))) {
+		if (0 >= (nr = write(fd, pcBuf, iLen))) {
 			c2cooked();
 			fprintf(stderr, "%s: lost connection\n", progname);
 			exit(3);
@@ -980,6 +980,7 @@
 static int SawUrg = 0;
 #if DO_POWER
 static char acPowCtl[128];
+static int Indir();
 
 /* We take a moment to call the power controller and ask		(ksb)
  * them about the console line we were chatting with.  We'll be right
@@ -991,7 +992,6 @@
 char *pcControl, *pcLine, *pcCurrent;
 {
 	register char *pcAt;
-	static int Indir();
 
 	if ((char *)0 != (pcAt = strchr(pcControl, '@'))) {
 		*pcAt++ = '\000';
