--- workman_stubs.c.orig	1997-06-11 18:14:01 UTC
+++ workman_stubs.c
@@ -158,6 +158,9 @@ main(argc, argv)
 		"Workman.Db.Shared", dbfiles);
 	if (dbfiles)
 		dbfiles = WMstrdup(dbfiles);
+	name = getenv("MUSIC_CD");
+	if (name)
+	    cd_device = name;
 
 	reverse_threshold = defaults_get_integer("workman.reverseThreshold",
 		"Workman.ReverseThreshold", reverse_threshold);
