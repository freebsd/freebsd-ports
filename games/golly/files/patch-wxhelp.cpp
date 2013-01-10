--- ./wxhelp.cpp.orig	2012-06-12 18:04:43.000000000 +0000
+++ ./wxhelp.cpp	2012-12-31 11:51:52.148991743 +0000
@@ -1026,7 +1026,7 @@
 
    } else if ( filepath.StartsWith(_("Help/")) ) {
       // prepend location of Golly so user can open help while running a script
-      wxString fullpath = gollydir + filepath;
+      wxString fullpath = wxString(DATADIR) + filepath;
       LoadPage(fullpath);
 
    } else {
