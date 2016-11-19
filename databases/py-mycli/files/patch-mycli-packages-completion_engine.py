Obtained from:	https://github.com/dbcli/mycli/commit/63a6339e451dfe537f1b7cf43758409abea52342

--- mycli/packages/completion_engine.py.orig	2016-09-18 04:19:04 UTC
+++ mycli/packages/completion_engine.py
@@ -197,6 +197,9 @@ def suggest_based_on_last_token(token, t
         return [{'type': 'column', 'tables': extract_tables(full_text)}]
     elif token_v in ('set', 'by', 'distinct'):
         return [{'type': 'column', 'tables': extract_tables(full_text)}]
+    elif token_v == 'as':
+        # Don't suggest anything for an alias
+        return []
     elif token_v in ('show'):
         return [{'type': 'show'}]
     elif token_v in ('to',):
