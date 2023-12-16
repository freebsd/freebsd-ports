--- src/complete.c.orig	2002-02-16 16:41:11 UTC
+++ src/complete.c
@@ -183,6 +183,7 @@ next:
 				sizeof(u_char *));
 		}
 next:
+	;
 	}
 	comps[i] = NULL;
 
