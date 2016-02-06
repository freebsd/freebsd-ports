--- rcsparse.c.orig	2016-02-06 23:25:25.000000000 +0100
+++ rcsparse.c	2016-02-06 23:33:35.539982000 +0100
@@ -1227,8 +1227,6 @@ valid_login(char *login_name)
 			return 0;
 		}
 	}
-	if ((char *)cp - login_name > _PW_NAME_LEN)
-		return 0;
 	return 1;
 }
 
