--- dot_parser.py.orig	2016-05-24 09:57:52.000000000 +0800
+++ dot_parser.py	2016-05-28 01:23:50.843873969 +0800
@@ -111,7 +111,7 @@
             add_elements(g, element)
 
         else:
-            raise ValueError, "Unknown element statement: %r " % element
+            raise ValueError("Unknown element statement: %r " % element)
 
 
     for g in top_graphs:
@@ -218,14 +218,14 @@
                 defaults_edge.update(element.attrs)
 
             else:
-                raise ValueError, "Unknown DefaultStatement: %s " % element.default_type
+                raise ValueError("Unknown DefaultStatement: %s " % element.default_type)
 
         elif isinstance(element, P_AttrList):
 
             g.obj_dict['attributes'].update(element.attrs)
 
         else:
-            raise ValueError, "Unknown element statement: %r" % element
+            raise ValueError("Unknown element statement: %r" % element)
 
 
 def push_graph_stmt(str, loc, toks):
@@ -267,7 +267,7 @@
     if default_type in ['graph', 'node', 'edge']:
         return DefaultStatement(default_type, attrs)
     else:
-        raise ValueError, "Unknown default statement: %r " % toks
+        raise ValueError("Unknown default statement: %r " % toks)
 
 
 def push_attr_list(str, loc, toks):
@@ -524,9 +524,9 @@
         else:
             return [g for g in tokens]
 
-    except ParseException, err:
+    except ParseException as err:
 
-        print err.line
-        print " "*(err.column-1) + "^"
-        print err
+        print(err.line)
+        print(" "*(err.column-1) + "^")
+        print(err)
         return None
