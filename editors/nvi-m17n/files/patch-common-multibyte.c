--- ../common/multibyte.c.orig	2017-01-07 18:04:20.087312000 +0900
+++ ../common/multibyte.c	2017-01-07 18:05:53.585988000 +0900
@@ -1455,7 +1455,7 @@
 			return ename;
 
 		for (i = 0; i < maxfunc; i++) {
-			if (maybe == (1 << i))
+			if (maybe & (1 << i))
 				return dt->name[i];
 		}
 	}
