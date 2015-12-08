--- cvsgraph.c.orig	2008-05-21 12:21:32 UTC
+++ cvsgraph.c
@@ -190,8 +190,8 @@ static void dump_dtext(char *p, dtext_t 
 {
 	printf("%sdtext.rev  : ", p);
 	dump_rev("", d->rev);
-	printf("%sdtext.log  : %d bytes\n", p, d->log ? strlen(d->log) : -1);
-	printf("%sdtext.text : %d bytes\n", p, d->text ? strlen(d->text) : -1);
+	printf("%sdtext.log  : %ld bytes\n", p, d->log ? (long) strlen(d->log) : -1);
+	printf("%sdtext.text : %ld bytes\n", p, d->text ? (long) strlen(d->text) : -1);
 	printf("\n");
 }
 
