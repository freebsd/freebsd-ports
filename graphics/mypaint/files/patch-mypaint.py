--- mypaint.py.orig	2013-04-16 20:22:02.000000000 +0200
+++ mypaint.py	2013-04-16 20:22:19.000000000 +0200
@@ -172,11 +172,6 @@
     print "DEBUG: localepath: ", localepath
     print "DEBUG: localepath_brushlib: ", localepath_brushlib
 
-    # Low-level bindtextdomain, required for GtkBuilder stuff.
-    locale.bindtextdomain("mypaint", localepath)
-    locale.bindtextdomain("libmypaint", localepath_brushlib)
-    locale.textdomain("mypaint")
-
     # Python gettext module.
     # See http://docs.python.org/release/2.7/library/locale.html
     gettext.bindtextdomain("mypaint", localepath)
