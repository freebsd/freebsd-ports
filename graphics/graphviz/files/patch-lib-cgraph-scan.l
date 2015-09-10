--- lib/cgraph/scan.l.orig	2014-04-13 22:40:25.000000000 +0200
+++ lib/cgraph/scan.l	2015-07-29 14:51:27.000000000 +0200
@@ -149,7 +149,7 @@
 	agxbput(&xb,buf);
 	agxbput(&xb,fname);
 	agxbput(&xb, " splits into two tokens\n");
-	agerr(AGWARN,agxbuse(&xb));
+	agerr(AGWARN, "%s", agxbuse(&xb));
 
 	agxbfree(&xb);
 	return 1;
@@ -225,7 +225,7 @@
 	agxbput (&xb, buf);
 	agxbput (&xb, yytext);
 	agxbput (&xb,"'\n");
-	agerr(AGERR,agxbuse(&xb));
+	agerr(AGERR, "%s", agxbuse(&xb));
 	agxbfree(&xb);
 }
 /* must be here to see flex's macro defns */
