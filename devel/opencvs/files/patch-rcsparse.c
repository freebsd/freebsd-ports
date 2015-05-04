--- rcsparse.c.orig	2015-05-04 09:15:45 UTC
+++ rcsparse.c
@@ -1228,8 +1228,6 @@ valid_login(char *login_name)
 			return 0;
 		}
 	}
-	if ((char *)cp - login_name > _PW_NAME_LEN)
-		return 0;
 	return 1;
 }
 
