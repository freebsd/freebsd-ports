--- tt.c.orig	Tue May 27 17:46:22 2003
+++ tt.c	Sat Sep 13 09:55:18 2003
@@ -21,6 +21,7 @@
 #include <fcntl.h>
 #include <errno.h>
 #include <pwd.h>
+#include <unistd.h>
 #include <sys/types.h>
 #include <sys/stat.h>
 
@@ -32,19 +33,19 @@
 
 /*-------------------------------------------------------------------------*/
 
-extern time_t time ();
+/* extern time_t time ();
 extern char *ctime ();
-/*extern char *malloc ();*/
+extern char *malloc ();
 extern char *getenv ();
 extern char *getlogin ();
-extern struct passwd *getpwuid ();
+extern struct passwd *getpwuid (); */
 
 static int get_key ();
 
 /*-------------------------------------------------------------------------*/
 
 char *LOCK_FILE = "/home/mike/lib/ttlock/ttlock";
-char *SCORE_FILE = "/home/mike/lib/ttscores";
+char *SCORE_FILE = "/var/games/ttscores";
 
 /* These four variables determine which game we're playing */
 struct piece *pieces = pieces4;
@@ -198,7 +199,7 @@
   (void) umask (0000);		/* 000 octal, just to make the point */
 
 #ifdef LOCKF
-  if ((lock_fd = open (SCORE_FILE, O_RDWR | O_CREAT, 0666)) == -1)
+  if ((lock_fd = open (SCORE_FILE, O_RDWR | O_CREAT, 0664)) == -1)
     die (LE_OPEN, "Couldn't open(2) score-file for lockf()");
 
   while (i++ < 5) {		/* Make up to five attempts */
