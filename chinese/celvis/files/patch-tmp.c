--- tmp.c.orig	1991-09-21 21:42:17 UTC
+++ tmp.c
@@ -21,6 +21,7 @@
 
 /* The FAIL() macro prints an error message and then exits. */
 #define FAIL(why,arg)	mode = MODE_EX; msg(why, arg); endwin(); HZ_abort(9)
+#define FAIL2(why,arg1,arg2)	mode = MODE_EX; msg(why, arg1, arg2); endwin(); HZ_abort(9)
 
 /* This is the name of the temp file */
 static char	tmpname[80];
@@ -91,7 +92,7 @@ int tmpstart(filename)
 			if (*o_readonly || (statb.st_mode & S_IJRON))
 #endif
 #if OS9
-			if we don't have write permission...
+			/* if we don't have write permission... */
 #endif
 #if ANY_UNIX
 			if (*o_readonly || !(statb.st_mode &
@@ -149,7 +150,7 @@ int tmpstart(filename)
 	tmpfd = open(tmpname, O_RDWR | O_BINARY);
 	if (tmpfd < 0)
 	{
-		FAIL("Can't create temporary file, errno=%d", errno);
+		FAIL2("Can't create temporary file (%s), errno=%d", tmpname, errno);
 		return 1;
 	}
 
