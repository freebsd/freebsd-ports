--- pgp.c.orig	2007-11-11 18:01:44.000000000 +0900
+++ pgp.c	2007-11-11 18:05:31.000000000 +0900
@@ -47,6 +47,9 @@
 #define LEOLINE	"\n"
 #endif
 
+static putENCRIPTED(FILE *src, FILE *dst, char *boundary, char *EOL);
+static putSIGNED(FILE *src, FILE* sign, FILE *dst, char *boundary, char *EOL);
+
 static pgp1(arg)
 	char *arg;
 {
