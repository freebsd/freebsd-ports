--- src/cpplib.c.orig	Fri Jan  9 16:44:23 2004
+++ src/cpplib.c	Fri Jan  9 16:44:51 2004
@@ -2828,7 +2828,7 @@
       else if (hp->type == T_CONST)
 	ok = !CPPOPTIONS (pfile)->done_initializing;
       else {
-	BADBRANCH;
+	ok = FALSE; /* Redefining anything else is bad. */
       }
 
       /* Print the warning if it's not ok.  */
