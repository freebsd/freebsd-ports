Obtained from:	https://github.com/dbcli/mycli/commit/63a6339e451dfe537f1b7cf43758409abea52342

--- mycli/packages/parseutils.py.orig	2015-10-16 13:27:27 UTC
+++ mycli/packages/parseutils.py
@@ -64,7 +64,7 @@ def last_word(text, include='alphanum_un
 # This code is borrowed from sqlparse example script.
 # <url>
 def is_subselect(parsed):
-    if not parsed.is_group():
+    if not parsed.is_group:
         return False
     for item in parsed.tokens:
         if item.ttype is DML and item.value.upper() in ('SELECT', 'INSERT',
