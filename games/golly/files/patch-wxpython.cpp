--- ./wxpython.cpp.orig	2012-06-12 18:04:44.000000000 +0000
+++ ./wxpython.cpp	2012-12-31 11:36:29.542997130 +0000
@@ -3026,7 +3026,7 @@
 
       // build absolute path to Scripts/Python folder and add to Python's
       // import search list so scripts can import glife from anywhere
-      wxString scriptsdir = gollydir + _("Scripts");
+      wxString scriptsdir = wxString(DATADIR) + _("Scripts");
       scriptsdir += wxFILE_SEP_PATH;
       scriptsdir += _("Python");
       // convert any \ to \\ and then convert any ' to \'
