--- html2h/html2h.c.orig	Sat Jul 19 02:31:37 2003
+++ html2h/html2h.c	Sat Jul 19 02:32:42 2003
@@ -6,15 +6,15 @@
 
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
+	printf("\
+html2h v0.1\n\
+usage:\n\
+	html2h input.html [output.h]\n\
+\n\
+	if output is not set, input.h will be generated and overwritten!\n\
+\n\
+	debug messages are written to stderr!\n\
+\n\
 ");
 
 	exit(0);
@@ -415,4 +415,4 @@
 {
 	fprintf(stderr, "%s%s\n", msg, comment);
 	exit(1);
-}
\ No newline at end of file
+}
