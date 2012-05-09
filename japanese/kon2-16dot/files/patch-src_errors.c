--- src/errors.c.orig	1997-01-24 09:36:22.000000000 +0900
+++ src/errors.c	2012-05-10 00:14:28.922550440 +0900
@@ -48,7 +48,7 @@
 		vfprintf(stderr, format, args);
 	} else {
 		VtEmu(head, strlen(head));
-		vsprintf(buf, format, args);
+		vsnprintf(buf, sizeof(buf), format, args);
 		VtEmu(buf, strlen(buf));
 	}
 }
