--- src/input.c.bak	Thu Oct  6 04:31:25 2005
+++ src/input.c	Sun Jul  9 12:42:12 2006
@@ -76,7 +76,11 @@
 
 # include <fcntl.h> 
 # include <sys/ioctl.h> 
+#if 0
 # include <termio.h> 
+#else
+# include <termios.h> 
+#endif
 
 char *getpass_hook(const char *prompt)
 {
@@ -89,23 +93,39 @@
 #else
 	int c, n = 0;
 	char tmp[1024];
+#if 0
 	struct termio tbuf, tbufsave;
+#else
+	struct termios tbuf, tbufsave;
+#endif
 	FILE *fd;
 
 	if((fd = fopen("/dev/tty", "rb")) == NULL) {
 		perror("fopen /dev/tty");
 		return NULL;
 	}
+#if 0
 	if (ioctl(fileno(fd), TCGETA, &tbuf) < 0) {
+#else
+	if (ioctl(fileno(fd), TIOCGETA, &tbuf) < 0) {
+#endif
 		perror("ioctl get");
 		fclose(fd);
 		return NULL;
 	}
 	tbufsave = tbuf;
+#if 0
 	tbuf.c_iflag &= ~(IUCLC | ISTRIP | IXON | IXOFF);
+#else
+	tbuf.c_iflag &= ~(ISTRIP | IXON | IXOFF);
+#endif
 	tbuf.c_lflag &= ~(ICANON | ISIG | ECHO);
 	tbuf.c_cc[4] = 1; /* MIN */
+#if 0
 	if (ioctl(fileno(fd), TCSETA, &tbuf) < 0) {
+#else
+	if (ioctl(fileno(fd), TIOCSETA, &tbuf) < 0) {
+#endif
 		perror("ioctl set");
 		fclose(fd);
 		return NULL;
@@ -132,7 +152,11 @@
 		fflush(stderr);
 	}
 	tmp[n] = '\0';
+#if 0
 	if (ioctl(fileno(fd), TCSETA, &tbufsave) < 0) {
+#else
+	if (ioctl(fileno(fd), TIOCSETA, &tbufsave) < 0) {
+#endif
 		perror("ioctl restore");
 		fclose(fd);
 		return NULL;
