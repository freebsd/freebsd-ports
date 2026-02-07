--- docs/conf.py.orig	2021-07-03 22:02:46 UTC
+++ docs/conf.py
@@ -53,10 +53,10 @@ exclude_patterns = ["_build", "Thumbs.db", ".DS_Store"
 
 # The theme to use for HTML and HTML Help pages.  See the documentation for
 # a list of builtin themes.
-from better import better_theme_path
+from sphinx_rtd_theme import get_html_theme_path
 
-html_theme_path = [better_theme_path]
-html_theme = "better"
+html_theme_path = [get_html_theme_path()]
+html_theme = "sphinx_rtd_theme"
 
 html_title = "<img> The Angband Manual"
 html_short_title = "Home"
