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
-extern char *ctime ();
-extern char *malloc ();
-extern char *getenv ();
-extern char *getlogin ();
-extern struct passwd *getpwuid ();
+//extern time_t time ();
+//extern char *ctime ();
+//extern char *malloc ();
+//extern char *getenv ();
+//extern char *getlogin ();
+//extern struct passwd *getpwuid ();
 
 static int get_key ();
 
 /*-------------------------------------------------------------------------*/
 
 char *LOCK_FILE = "/home/mike/lib/ttlock/ttlock";
-char *SCORE_FILE = "/home/mike/lib/ttscores";
+char *SCORE_FILE = "/var/games/ttscores";
 
 /* These four variables determine which game we're playing */
 struct piece *pieces = pieces4;
