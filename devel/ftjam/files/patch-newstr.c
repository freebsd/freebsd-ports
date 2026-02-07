--- newstr.c.orig	2014-08-07 15:39:56.000000000 +0200
+++ newstr.c	2014-08-07 15:40:34.000000000 +0200
@@ -82,6 +82,7 @@
 void
 freestr( const char *s )
 {
+	(void)s; // is this supposed to be free(s); ?
 }
 
 /*
