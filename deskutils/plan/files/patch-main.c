--- main.c.orig	2017-10-17 00:54:07.000000000 -0700
+++ main.c	2023-06-25 17:47:19.371176000 -0700
@@ -123,7 +123,7 @@
 	XGCValues		gcval;
 
 #ifdef __FreeBSD__
-	atexit(plan_exit);
+	atexit((void *)plan_exit);
 #endif
 	interactive = FALSE;
 	if ((progname = strrchr(argv[0], '/')) && progname[1])
