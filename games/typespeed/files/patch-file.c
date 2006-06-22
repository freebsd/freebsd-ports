--- file.c.orig	Thu Jun 22 12:15:04 2006
+++ file.c	Thu Jun 22 12:18:11 2006
@@ -393,7 +393,7 @@
 	entry[8] = newentry(  0, 0, 0  , 0  ,  0, "None");
 	entry[9] = newentry(  0, 0, 0  , 0  ,  0, "None");
 
-	n = snprintf(filetys, sizeof(filetys), "%s/high.%s", highdir, sanafile);
+	n = snprintf(filetys, sizeof(filetys), "%s/high.%s.default", highdir, sanafile);
 	if (n < 6 || (size_t)n > sizeof(filetys) - 1)
 		return 1;
 
