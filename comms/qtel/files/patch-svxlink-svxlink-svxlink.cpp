--- ../svxlink-11.05.orig/svxlink/svxlink/svxlink.cpp	2011-04-21 05:46:47.000000000 -0700
+++ svxlink/svxlink/svxlink.cpp	2012-05-28 10:27:55.000000000 -0700
@@ -345,16 +345,16 @@
     cfg_filename += "/.svxlink/svxlink.conf";
     if (!cfg.open(cfg_filename))
     {
-      cfg_filename = "/etc/svxlink/svxlink.conf";
+      cfg_filename = "%%LOCALBASE%%/etc/svxlink/svxlink.conf";
       if (!cfg.open(cfg_filename))
       {
-	cfg_filename = "/etc/svxlink.conf";
+	cfg_filename = "%%LOCALBASE%%/etc/svxlink.conf";
 	if (!cfg.open(cfg_filename))
 	{
 	  cerr << "*** ERROR: Could not open configuration file. Tried:\n"
       	       << "\t" << home_dir << "/.svxlink/svxlink.conf\n"
-      	       << "\t/etc/svxlink/svxlink.conf\n"
-	       << "\t/etc/svxlink.conf\n"
+      	       << "\t%%LOCALBASE%%/etc/svxlink/svxlink.conf\n"
+	       << "\t%%LOCALBASE%%/etc/svxlink.conf\n"
 	       << "Possible reasons for failure are: None of the files exist,\n"
 	       << "you do not have permission to read the file or there was a\n"
 	       << "syntax error in the file\n";
