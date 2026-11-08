--- symbols-check.py.orig	2026-05-29 08:49:42 UTC
+++ symbols-check.py
@@ -11,6 +11,7 @@ PLATFORM_SYMBOLS = [
     '__bss_end__',
     '__bss_start__',
     '__bss_start',
+    '__cxa_finalize',
     '__end__',
     '_bss_end__',
     '_edata',
@@ -36,7 +37,7 @@ def get_symbols(nm, lib):
         if len(fields) == 2 or fields[1] == 'U':
             continue
         symbol_name = fields[0]
-        if platform_name == 'Linux':
+        if platform_name == 'Linux' or platform_name == 'FreeBSD':
             if symbol_name in PLATFORM_SYMBOLS:
                 continue
         elif platform_name == 'Darwin':
