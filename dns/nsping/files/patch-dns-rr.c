--- dns-rr.c.orig	Mon Jul  4 12:02:22 2005
+++ dns-rr.c	Mon Jul  4 12:02:39 2005
@@ -23,7 +23,7 @@
 
 	len = dns_string(name, dp, MAXDNAME);
 	if(len < 0)
-		return(NULL);
+		return(0);
 
 	dp += len;
 
