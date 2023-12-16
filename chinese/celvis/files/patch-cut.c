--- cut.c.orig	1991-04-03 20:41:47 UTC
+++ cut.c
@@ -36,6 +36,7 @@ static char	cbname;	/* name chosen for next cut/paste 
 
 static char	cbname;	/* name chosen for next cut/paste operation */
 
+static cutfree(struct cutbuf *buf);
 
 #ifndef NO_RECYCLE
 /* This function builds a list of all blocks needed in the current tmp file
