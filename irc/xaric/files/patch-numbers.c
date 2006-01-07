--- numbers.c.orig	Sun Jan  8 07:57:54 2006
+++ numbers.c	Sun Jan  8 07:58:02 2006
@@ -986,7 +986,7 @@
 
 		if (!ArgList[1] || !*ArgList[1])
 		    break;
-		sscanf(ArgList[1], "%lu", &tme);
+		sscanf(ArgList[1], "%u", &tme);
 		this_sucks = ctime(&tme);
 		this_sucks[strlen(this_sucks) - 1] = '\0';
 
