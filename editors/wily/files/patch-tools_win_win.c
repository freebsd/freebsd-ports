--- tools/win/win.c.orig	Mon Dec  2 17:44:13 1996
+++ tools/win/win.c	Tue Jan 31 22:19:30 2006
@@ -680,10 +680,6 @@
 	/* e.g., on Digital UNIX or Solaris */
 
 	{
-		extern char *ptsname();
-		extern int grantpt();
-		extern int unlockpt();
-		
 		master = open("/dev/ptmx", O_RDWR);
 		if (master < 0) {
 			error("open() failed" here);
