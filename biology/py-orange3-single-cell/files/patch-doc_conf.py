# add_stylesheet() deprecated on Sphinx 4.0
# https://www.sphinx-doc.org/en/master/extdev/deprecated.html
--- doc/conf.py.orig	2018-10-15 08:43:14 UTC
+++ doc/conf.py
@@ -288,4 +288,4 @@ texinfo_documents = [
 #texinfo_no_detailmenu = False
 
 def setup(app):
-    app.add_stylesheet('style.css')
+    app.add_css_file('style.css')
