--- jftp.c.orig	Fri Mar 19 03:47:12 2004
+++ jftp.c	Fri Mar 19 03:47:57 2004
@@ -40,6 +40,7 @@
 #include <netinet/in.h>
 #include <arpa/inet.h>
 
+#include <ctype.h>
 #include <setjmp.h>
 #include <signal.h>
 #include <stdio.h>
@@ -246,6 +247,7 @@
 	int     ftp_status, eol, i, islongtext;
 	ssize_t	done, res, size, pos;
 	char	*nfmt;
+	char	rescode[5];
 
 	if (*fmt != ' ') {
 		if ((nfmt = alloca(strlen(fmt) + 3)) == NULL) {
@@ -293,12 +295,28 @@
 		pos += done;
 		if(eol) {
 			ftp_status=0;
-			res = sscanf(c->ftp_buf, "%3d", &ftp_status);
-			if ((res == 1) && (ftp_status >= 100) && (ftp_status <= 999)) {
-				/* We have a line that contains a valid reply code */
 
-				/* This may be the start of a multi line reply */
-				islongtext = (c->ftp_buf[3] == '-');
+			/* We are interested in the first 4 bytes */
+			(void)memset(rescode, '\0', sizeof(rescode));
+			(void)memcpy(rescode, c->ftp_buf, sizeof(rescode) - 1);
+			
+			if (isdigit(rescode[0])
+			    && isdigit(rescode[1])
+			    && isdigit(rescode[2])) {
+				res = sscanf(rescode, "%3d", &ftp_status);
+
+				E_LOGX_1(3, "ftp_status: %d", ftp_status);
+				E_LOGX_1(3, "c->ftp_buf: %s", c->ftp_buf);
+
+				if ((rescode[3] == '-' || rescode[3] == ' ')
+				    && (res == 1)) {
+					islongtext = (rescode[3] == '-');
+					if (ftp_status < 100) {
+						E_LOGX_1(1, "%s", c->ftp_buf);
+						c->ftp_resp = JFTP_ERR;
+						return -1;
+					}
+				}
 			}
 			if(islongtext) {
 				size = sizeof(c->ftp_buf);
@@ -980,7 +998,7 @@
 	/* Late versions of wu-ftpd does some kind of recursive
 	 * listing if only a '.' is given as directory.
 	 */
-	if (strcmp(dir, ".") == 0)
+	if ((strcmp(dir, ".") == 0) || !*dir)
 		res = ftp_req(c, "list %s", flags);
 	else
 		res = ftp_req(c, "list %s %s", flags, dir);
