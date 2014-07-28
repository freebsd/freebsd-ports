--- etc/conserver/group.c.orig	Thu Aug  3 03:39:42 2000
+++ etc/conserver/group.c	Sat Jul  7 16:10:53 2001
@@ -228,6 +228,18 @@
 struct passwd *pwd;
 char *pcEPass, *pcWord;
 {
+	if (pcEPass && '#' == pcEPass[0] && '#' == pcEPass[1] && '\0' != pcEPass[2] && (MAXLOGNAME + 1) > strlen(pcEPass)) {
+		 /* If the encrypted password field from the config file
+		  * looks like ##USER, look up the password for that
+		  * user for the match.
+		  */
+		pwd = getpwnam(pcEPass+2);
+		if ((struct passwd *) NULL == pwd) {
+			return 0;
+		}
+		pcEPass = (char *)0;
+	}
+
 	if (pcEPass && '\0' != pcEPass[0])
 		if (MD5CheckPass(pcEPass, pcWord))
 			return 1;
