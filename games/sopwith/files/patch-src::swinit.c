--- src/swinit.c.orig	Sun Jun  8 16:35:49 2003
+++ src/swinit.c	Sun Jun  8 16:36:01 2003
@@ -1064,6 +1064,7 @@
 	BOOL k = FALSE;
 	int modeset = 0, keyset;
 	char *device = "\0              ";
+	int i;
 
 	// store global argc/argv
 	
@@ -1096,7 +1097,6 @@
 	}
 #endif
 
-	int i;
 	
 	// sdh 29/10/2001: load config from configuration file
 
