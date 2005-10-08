--- cvsgraph.c.orig	Wed Jun 15 05:36:59 2005
+++ cvsgraph.c	Wed Sep 21 11:06:22 2005
@@ -191,8 +191,8 @@
 {
 	printf("%sdtext.rev  : ", p);
 	dump_rev("", d->rev);
-	printf("%sdtext.log  : %d bytes\n", p, d->log ? strlen(d->log) : -1);
-	printf("%sdtext.text : %d bytes\n", p, d->text ? strlen(d->text) : -1);
+	printf("%sdtext.log  : %ld bytes\n", p, d->log ? (long) strlen(d->log) : -1);
+	printf("%sdtext.text : %ld bytes\n", p, d->text ? (long) strlen(d->text) : -1);
 	printf("\n");
 }
 
