--- src/ircd.c	2009-03-01 19:37:58.000000000 +0100
+++ src/ircd.c	2009-08-18 16:20:39.000000000 +0200
@@ -1369,9 +1369,9 @@
 	}
 #endif
 #ifndef _WIN32
-	mkdir("tmp", S_IRUSR|S_IWUSR|S_IXUSR); /* Create the tmp dir, if it doesn't exist */
+	mkdir("%%RUNDIR%%/tmp", S_IRUSR|S_IWUSR|S_IXUSR); /* Create the tmp dir, if it doesn't exist */
 #else
-	mkdir("tmp");
+	mkdir("%%RUNDIR%%/tmp");
 #endif
 #ifndef _WIN32
 	/*
