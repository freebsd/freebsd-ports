--- fsplit/fsplit.c.orig	2000-01-30 21:03:32 UTC
+++ fsplit/fsplit.c
@@ -97,7 +97,7 @@ struct stat sbuf;
 
 #define trim(p)	while (*p == ' ' || *p == '\t') p++
 
-int   getline __P((void));
+int   get_line __P((void));
 void  get_name __P((char *, int));
 char *functs __P((char *));
 int   lend __P((void));
@@ -171,7 +171,7 @@ char **argv;
 		errx(1, "can not open %s", x);
 	nflag = 0;
 	rv = 0;
-	while (getline() > 0) {
+	while (get_line() > 0) {
 		rv = 1;
 		fprintf(ofp, "%s", buf);
 		if (lend())		/* look for an 'end' statement */
@@ -263,7 +263,7 @@ int letters;
 }
 
 int
-getline()
+get_line()
 {
 	register char *ptr;
 
