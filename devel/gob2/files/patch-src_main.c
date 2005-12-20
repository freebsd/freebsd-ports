--- src/main.c.orig	Tue Dec 20 20:28:09 2005
+++ src/main.c	Tue Dec 20 20:28:55 2005
@@ -3078,7 +3078,7 @@
 	outfilebase = g_strconcat (fullfilebase, for_cpp ? ".cc" : ".c", NULL);
 	outfile = g_strconcat(outfilebase, no_touch ? "#gob#" : "", NULL);
 
-	outfilehbase = g_strconcat (fullfilebase, ".h");
+	outfilehbase = g_strconcat (fullfilebase, ".h", NULL);
 	outfileh = g_strconcat(outfilehbase, no_touch_headers ? "#gob#" : "", NULL);
 
 	if ((privates > 0 || protecteds > 0 ||
