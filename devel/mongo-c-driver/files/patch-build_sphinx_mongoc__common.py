--- build/sphinx/mongoc_common.py.orig	2026-02-03 15:13:43 UTC
+++ build/sphinx/mongoc_common.py
@@ -146,17 +146,17 @@ def generate_html_redirs(app: Sphinx, page: str, templ
     redirect_file = out_index_html.parent.parent / f"{slug}.html"
     # HACK: handle_page() is not properly reentrant. Save and restore state for
     # this page while we generate our redirects page:
-    prev_scripts = builder.script_files[:]
-    prev_css = builder.css_files[:]
+    prev_scripts = builder.globalcontext['script_files'][:]
+    prev_css = builder.globalcontext['css_files'][:]
     builder.handle_page(
         f"redirect-for-{page}",
         {"target": page, "writing-redirect": 1},
         str(Path(__file__).parent.resolve() / "redirect.t.html"),
-        str(redirect_file),
+        outfilename=str(redirect_file),
     )
     # Restore prior state:
-    builder.script_files[:] = prev_scripts
-    builder.css_files[:] = prev_css
+    builder.globalcontext['script_files'][:] = prev_scripts
+    builder.globalcontext['css_files'][:] = prev_css
     sphinx_log.debug("Wrote redirect: %r -> %r", path, page)
 
 def mongoc_common_setup(app: Sphinx):
