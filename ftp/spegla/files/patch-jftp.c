--- jftp.c.orig	Thu Mar 23 17:34:21 2006
+++ jftp.c	Thu Mar 23 17:39:39 2006
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
@@ -455,17 +473,22 @@
 		c->ftp_resp = JFTP_ERR;
 		return -1;
 	}
-	if (ftp_req(c, "user %s", c->ftp_user_name) < 0 || c->ftp_resp != 331) {
+	if (ftp_req(c, "user %s", c->ftp_user_name) < 0 
+		|| (c->ftp_resp != 331 && c->ftp_resp != 230)) {
 		E_LOGX_1(0, "Username %s: failed", c->ftp_user_name);
 		FD_CLOSE(c->ftp_com);
 		c->ftp_resp = JFTP_ERR;
 		return -1;
 	}
-	if (ftp_req(c, "pass %s", c->ftp_password) < 0 || c->ftp_resp != 230) {
-		E_LOGX(0, "Password xxxxx: failed");
-		FD_CLOSE(c->ftp_com);
-		c->ftp_resp = JFTP_ERR;
-		return -1;
+	/* USER command can respond 230 immediately in some cases */
+	if (c->ftp_resp != 230) {
+		if (ftp_req(c, "pass %s", c->ftp_password) < 0
+			|| c->ftp_resp != 230) {
+			E_LOGX(0, "Password xxxxx: failed");
+			FD_CLOSE(c->ftp_com);
+			c->ftp_resp = JFTP_ERR;
+			return -1;
+		}
 	}
 	c->ftp_resp = 0;
 	if (ftp_req(c, "TYPE I") < 0 || c->ftp_resp != 200) {
@@ -980,7 +1003,7 @@
 	/* Late versions of wu-ftpd does some kind of recursive
 	 * listing if only a '.' is given as directory.
 	 */
-	if (strcmp(dir, ".") == 0)
+	if ((strcmp(dir, ".") == 0) || !*dir)
 		res = ftp_req(c, "list %s", flags);
 	else
 		res = ftp_req(c, "list %s %s", flags, dir);
