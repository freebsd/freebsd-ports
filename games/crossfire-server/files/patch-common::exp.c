--- common/exp.c.orig	Sat Mar 27 06:59:25 2004
+++ common/exp.c	Thu Aug 26 05:56:20 2004
@@ -190,7 +190,7 @@
 		exit(1);
 	    }
 
-	    tmpexp = atoll(cp);
+	    tmpexp = strtoll(cp, (char **)NULL, 10);
 	    /* Do some sanity checking - if value is bogus, just exit because
 	     * the table otherwise is probably in an inconsistent state
 	     */
