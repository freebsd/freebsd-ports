--- buildsystem/pxdgen.py.orig	2020-08-15 10:50:07 UTC
+++ buildsystem/pxdgen.py
@@ -23,6 +23,7 @@ class ParserError(Exception):
     """
     Represents a fatal parsing error in PXDGenerator.
     """
+
     def __init__(self, filename, lineno, message):
         super().__init__("{}:{} {}".format(filename, lineno, message))
 
@@ -218,8 +219,11 @@ class PXDGenerator:
             return self.handle_token(token, val)
 
         def handle_state_1(self, token, val, namespace_parts):
+            # Patch from upstream, commit 3aa91ea4d4a72a5f3b6f90ad0390b9e07de7aa77
             # we're inside a namespace definition; expect Token.Name
-            if token != Token.Name:
+            # TODO: pygments 2.9 correctly reports Token.Name.Namespace
+            #       we can require this version eventually and change the condition
+            if token not in Token.Name:
                 raise self.parser_error(
                     "expected identifier after 'namespace'")
             namespace_parts.append(val)
