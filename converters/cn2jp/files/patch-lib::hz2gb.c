--- lib/hz2gb.c.orig	Mon Nov 18 23:42:53 2002
+++ lib/hz2gb.c	Mon Nov 18 23:50:14 2002
@@ -64,7 +64,7 @@
 int pass8 = FALSE;	/* flat for parsing all 8 bits of a character */
 int termStyle = FALSE;	/* flag for ignoring line-continuation markers */
 int errorCount = 0;	/* number of parsing errors detected */
-FILE *ferr = stdout;	/* error reporting channel */
+#define ferr stdout	/* error reporting channel */
 
 void usage(), filter(), EOFerror(), ESCerror(), GBerror(), GBerror1();
 void GBtoSGB();
