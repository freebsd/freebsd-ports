--- scf.c.orig	2000-11-16 08:15:33 UTC
+++ scf.c
@@ -1009,7 +1009,7 @@ key_value_pair (SCF *scf, uchar *line, s
 			if (*(p+1) == '\0')
 				break;
 		}
-		STOP:
+		STOP:;
 	} else {
 		/* it's a int
 		 */
