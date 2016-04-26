--- mypaint.py.orig	2012-12-31 16:35:54 UTC
+++ mypaint.py
@@ -172,11 +172,6 @@ if __name__ == '__main__':
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
