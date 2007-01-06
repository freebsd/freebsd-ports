--- src/common/cfgfiles.c.orig	Fri Jan  5 18:55:27 2007
+++ src/common/cfgfiles.c	Fri Jan  5 18:55:40 2007
@@ -45,7 +45,7 @@
 	int cmd_len = 1, name_len;
 
 	/* remove <2.8.0 stuff */
-	if (!strcmp (cmd, "AWAY") & !strcmp (name, "BACK"))
+	if (!strcmp (cmd, "away") & !strcmp (name, "BACK"))
 		return;
 
 	if (cmd)
