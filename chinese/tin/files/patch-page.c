--- src/page.c.orig	Wed Jan  8 00:19:22 2003
+++ src/page.c	Wed Jan  8 00:19:47 2003
@@ -980,7 +980,7 @@
 			}
 		} else
 #	endif /* MULTIBYTE_ABLE && !NO_LOCALE */
-			if ((int) strlen(line) >= cCOLS)
+			if ((int) strlen(line) >= cCOLS && strncasecmp(tinrc.mm_local_charset, "Big5", 4))
 				bytes = cCOLS;
 		line[bytes] = '\0';
 
