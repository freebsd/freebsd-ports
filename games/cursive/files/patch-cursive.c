--- cursive.c.orig	Sat Dec  4 17:20:55 1999
+++ cursive.c	Sat Dec  4 17:21:32 1999
@@ -128,7 +128,7 @@
 	else
 	{
 		/* Message from standard input */
-		while (gets(message) != NULL)
+		while (fgets(message, sizeof(message), stdin) != NULL)
 			prline(message);
 	}
 }
