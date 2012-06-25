--- ../svxlink-11.05.orig/svxlink/remotetrx/remotetrx.cpp	2011-04-21 06:45:13.000000000 -0700
+++ svxlink/remotetrx/remotetrx.cpp	2012-05-28 10:27:55.000000000 -0700
@@ -371,7 +371,7 @@
     cfg_filename += "/.svxlink/remotetrx.conf";
     if (!cfg.open(cfg_filename))
     {
-      cfg_filename = "/etc/svxlink/remotetrx.conf";
+      cfg_filename = "%%LOCALBASE%%/etc/svxlink/remotetrx.conf";
       if (!cfg.open(cfg_filename))
       {
 	cfg_filename = "/etc/remotetrx.conf";
@@ -379,7 +379,7 @@
 	{
 	  cerr << "*** ERROR: Could not open configuration file. Tried:\n"
       	       << "\t" << home_dir << "/.svxlink/remotetrx.conf\n"
-      	       << "\t/etc/svxlink/remotetrx.conf\n"
+      	       << "\t%%LOCALBASE%%/etc/svxlink/remotetrx.conf\n"
 	       << "\t/etc/remotetrx.conf\n"
 	       << "Possible reasons for failure are: None of the files exist,\n"
 	       << "you do not have permission to read the file or there was a\n"
