--- dis/test/disscope.c.orig	1998-12-10 23:58:01.000000000 +0100
+++ dis/test/disscope.c	2011-06-21 13:01:46.689444826 +0200
@@ -172,7 +172,7 @@
 #endif
 		++ count;
 	}
-	return;
+	return 0;
 }
 
 char *
