--- ../common/multibyte.c.orig	2017-11-17 21:47:04.305764000 +0900
+++ ../common/multibyte.c	2017-11-17 21:58:19.218532000 +0900
@@ -1454,8 +1454,9 @@
 		if (maybe == 0)
 			return ename;
 
+		if ( (maxfunc!=1) && (try==maybe) ) continue ;
 		for (i = 0; i < maxfunc; i++) {
-			if (maybe == (1 << i))
+			if (maybe & (1 << i))
 				return dt->name[i];
 		}
 	}
