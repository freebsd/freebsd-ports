-- tests/test_integration.py: normalize quote HTML entities when comparing
-- expected and generated HTML. Newer pygments/Jinja2 emit raw quotes while
-- the bundled fixtures still use &quot;/&#39; entities.
-- Upstream issue: https://github.com/Bachmann1234/diff-cover/issues

--- tests/test_integration.py.orig	2026-09-14 14:52:48 UTC
+++ tests/test_integration.py
@@ -105,6 +105,9 @@ def clean_html(html, clear_inline_css):
 def clean_html(html, clear_inline_css):
     if clear_inline_css:
         html = re.sub("<style>.*</style>", "", html, flags=re.DOTALL)
+    # Normalize HTML entity variants of quotes to tolerate pygments/Jinja2
+    # escaping differences across dependency versions.
+    html = html.replace("&quot;", '"').replace("&#39;", "'")
     return html.strip()
 
 
