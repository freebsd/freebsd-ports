--- rcsparse.c.orig	2011-04-20 21:08:22.000000000 +0200
+++ rcsparse.c	2011-04-20 21:08:46.000000000 +0200
@@ -1221,8 +1221,6 @@
 			return 0;
 		}
 	}
-	if ((char *)cp - login_name > _PW_NAME_LEN)
-		return 0;
 	return 1;
 }
 
