--- calendar.c.orig	2020-10-18 03:01:26 UTC
+++ calendar.c
@@ -228,6 +228,7 @@ main(int argc, char *argv[])
 				if (setusercontext(lc, pw, pw->pw_uid,
 				    LOGIN_SETALL) != 0)
 					errx(1, "setusercontext");
+				setenv("HOME", pw->pw_dir, 1);
 				cal();
 				exit(0);
 			}
