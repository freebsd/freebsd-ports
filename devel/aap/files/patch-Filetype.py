--- Filetype.py.orig	2009-05-14 15:19:42.000000000 +0200
+++ Filetype.py	2009-05-14 15:20:50.000000000 +0200
@@ -1414,12 +1414,12 @@
             rline = items[1]
         rline_len = len(rline)
         # isolate first argument, which may be in quotes
-        as = 0
-        if as < rline_len:
-            if rline[as] == '"' or rline[as] == "'":
-                quote = rline[as]
-                as = as + 1
-                ae = as
+        vas = 0
+        if vas < rline_len:
+            if rline[vas] == '"' or rline[vas] == "'":
+                quote = rline[vas]
+                vas = vas + 1
+                ae = vas
                 while ae < rline_len and rline[ae] != quote:
                     ae = ae + 1
                 if ae == rline_len:
@@ -1427,11 +1427,11 @@
                                            % (line_idx + recipe_line_nr, line))
                 n = ae + 1
             else:
-                ae = as
+                ae = vas
                 while ae < rline_len and rline[ae] != ' ' and rline[ae] != '\t':
                     ae = ae + 1
                 n = ae
-            arg1 = rline[as:ae]
+            arg1 = rline[vas:ae]
         else:
             arg1 = ''
             n = rline_len
