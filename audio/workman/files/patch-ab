--- workman_stubs.c.orig	Sat Feb 14 08:47:37 1998
+++ workman_stubs.c	Sat Feb 14 08:50:16 1998
@@ -163,6 +163,9 @@
 		"Workman.Db.Shared", dbfiles);
 	if (dbfiles)
 		dbfiles = WMstrdup(dbfiles);
+	name = getenv("MUSIC_CD");
+	if (name)
+	    cd_device = name;
 
 	reverse_threshold = defaults_get_integer("workman.reverseThreshold",
 		"Workman.ReverseThreshold", reverse_threshold);
