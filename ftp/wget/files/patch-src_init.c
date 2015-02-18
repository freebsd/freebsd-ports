--- src/init.c.orig	2014-10-27 09:18:13.000000000 +0100
+++ src/init.c	2014-11-10 10:39:51.683089107 +0100
@@ -170,9 +170,6 @@
   { "dotsinline",       &opt.dots_in_line,      cmd_number },
   { "dotspacing",       &opt.dot_spacing,       cmd_number },
   { "dotstyle",         &opt.dot_style,         cmd_string }, /* deprecated */
-#ifdef HAVE_SSL
-  { "egdfile",          &opt.egd_file,          cmd_file },
-#endif
   { "excludedirectories", &opt.excludes,        cmd_directory_vector },
   { "excludedomains",   &opt.exclude_domains,   cmd_vector },
   { "followftp",        &opt.follow_ftp,        cmd_boolean },
