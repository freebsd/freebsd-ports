--- src/ircd.c	Wed Oct 27 20:45:26 2004
+++ src/ircd.c	Mon Feb  7 04:19:55 2005
@@ -1182,9 +1182,9 @@
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
