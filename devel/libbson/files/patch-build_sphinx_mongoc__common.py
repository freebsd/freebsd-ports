--- build/sphinx/mongoc_common.py.orig	2023-12-13 02:45:10 UTC
+++ build/sphinx/mongoc_common.py
@@ -145,7 +145,7 @@ def generate_html_redirs(app: Sphinx, page: str, templ
         return
     if page == "index" or page.endswith(".index"):
         return
-    path = app.project.doc2path(page, absolute=True)
+    path = app.project.doc2path(page)
     out_index_html = Path(builder.get_outfilename(page))
     slug = out_index_html.parent.name
     redirect_file = out_index_html.parent.parent / f"{slug}.html"
