# add_stylesheet() deprecated on Sphinx 4.0
# https://www.sphinx-doc.org/en/master/extdev/deprecated.html
--- docs/conf.py.orig	2019-01-27 13:48:05 UTC
+++ docs/conf.py
@@ -21,7 +21,7 @@ exec(open("../src/paperless/version.py").read())
 
 # Believe it or not, this is the officially sanctioned way to add custom CSS.
 def setup(app):
-    app.add_stylesheet("custom.css")
+    app.add_css_file("custom.css")
 
 # If extensions (or modules to document with autodoc) are in another directory,
 # add these directories to sys.path here. If the directory is relative to the
