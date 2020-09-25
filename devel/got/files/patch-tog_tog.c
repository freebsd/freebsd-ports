--- tog/tog.c.orig	2020-09-25 11:58:47 UTC
+++ tog/tog.c
@@ -5654,7 +5654,7 @@ main(int argc, char *argv[])
 
 	argc -= optind;
 	argv += optind;
-	optind = 0;
+	optind = 1;
 	optreset = 1;
 
 	if (Vflag) {
