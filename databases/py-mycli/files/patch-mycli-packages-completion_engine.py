--- mycli/packages/completion_engine.py.orig	2020-07-25 03:46:06 UTC
+++ mycli/packages/completion_engine.py
@@ -2,7 +2,6 @@ import os
 import sys
 import sqlparse
 from sqlparse.sql import Comparison, Identifier, Where
-from sqlparse.compat import text_type
 from .parseutils import last_word, extract_tables, find_prev_keyword
 from .special import parse_special_command
 
@@ -55,7 +54,7 @@ def suggest_type(full_text, text_before_cursor):
         stmt_start, stmt_end = 0, 0
 
         for statement in parsed:
-            stmt_len = len(text_type(statement))
+            stmt_len = len(str(statement))
             stmt_start, stmt_end = stmt_end, stmt_end + stmt_len
 
             if stmt_end >= current_pos:
