--- html2h/html2h.c.orig	2014-11-24 13:09:14.000000000 -0800
+++ html2h/html2h.c	2014-11-24 13:25:12.000000000 -0800
@@ -6,15 +6,10 @@
 
 void usage()
 {
-	printf("
-html2h v0.1
-usage:
-	html2h input.html [output.h]
-
-	if output is not set, input.h will be generated and overwritten!
-
-	debug messages are written to stderr!
-
+	printf("html2h v0.1\nusage:\n \
++	html2h input.html [output.h]\n\n \
++	if output is not set, input.h will be generated and overwritten!\n\n \
++	debug messages are written to stderr!\n\n \
 ");
 
 	exit(0);
@@ -415,4 +410,6 @@
 {
 	fprintf(stderr, "%s%s\n", msg, comment);
 	exit(1);
-}
\ No newline at end of file
+
+}
+
