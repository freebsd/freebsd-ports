--- tog/tog.c.orig	2020-09-14 19:31:57 UTC
+++ tog/tog.c
@@ -5645,7 +5645,7 @@ main(int argc, char *argv[])
 
 	argc -= optind;
 	argv += optind;
-	optind = 0;
+	optind = 1;
 	optreset = 1;
 
 	if (Vflag) {
