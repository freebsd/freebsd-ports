--- plugins/diff/diff.c.orig	Sat Oct 18 16:02:21 2003
+++ plugins/diff/diff.c	Sat Oct 18 16:05:51 2003
@@ -56,7 +56,6 @@
 #include <gedit/gedit-mdi.h>
 #include <gedit/gedit-output-window.h>
 
-
 #define DIFF_BASE_KEY 		"/apps/gedit-2/plugins/diff"
 #define DIFF_LOCATION_KEY	"/diff-program-location"
 #define UNIFIED_FORMAT_KEY	"/use-unified-format"
@@ -438,7 +437,7 @@
 
 			case GTK_RESPONSE_HELP:
 				/* FIXME: choose a better link id */
-				gnome_help_display ("gedit.xml", "gedit-use-plugins", &error);
+				gnome_help_display ("gedit.xml", "gedit-compare-files-plugin", &error);
 	
 				if (error != NULL)
 				{
@@ -959,7 +958,9 @@
 	
 	temp = gedit_plugin_locate_program (DIFF_PROGRAM_NAME,
 					    plugin_name, 
-					    parent);
+					    parent,
+					    DIFF_BASE_KEY DIFF_LOCATION_KEY,
+					    "gedit-compare-files-configure");
 
 	if (temp != NULL)
 	{
