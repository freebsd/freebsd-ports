--- src/logutmp.c.old	Sat May 26 16:07:13 2001
+++ src/logutmp.c	Sat May 26 16:07:39 2001
@@ -45,7 +45,7 @@
  */
 
 void
-login(const UTMP *ut)
+ftpd_login(const UTMP *ut)
 {
 	UTMP ubuf;
 
@@ -85,7 +85,7 @@
 }
 
 int
-logout(const char *line)
+ftpd_logout(const char *line)
 {
 	UTMP ut;
 	int rval;
