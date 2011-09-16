--- ../src/main.c.orig	2011-09-16 09:04:34.000000000 +0800
+++ ../src/main.c	2011-09-16 09:06:34.000000000 +0800
@@ -1491,7 +1491,7 @@ cleanup()
 	uucpunlock(n0);
 }
 
-void
+int
 main(argc, argv)
 	int argc;
 	char **argv;
