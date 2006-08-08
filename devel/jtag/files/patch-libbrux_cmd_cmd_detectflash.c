--- libbrux/cmd/cmd_detectflash.c.orig	Sat Aug  5 23:45:49 2006
+++ libbrux/cmd/cmd_detectflash.c	Sat Aug  5 23:50:04 2006
@@ -40,7 +40,7 @@
 		return 1;
 	}
 
-	detectflash( bus );
+	detectflash( bus, 0 );
 
 	return 1;
 }
