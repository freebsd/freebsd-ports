--- cut.c.orig	Wed May 30 19:50:50 2007
+++ cut.c	Wed May 30 19:51:41 2007
@@ -36,6 +36,7 @@
 
 static char	cbname;	/* name chosen for next cut/paste operation */
 
+static cutfree(struct cutbuf *buf);
 
 #ifndef NO_RECYCLE
 /* This function builds a list of all blocks needed in the current tmp file
