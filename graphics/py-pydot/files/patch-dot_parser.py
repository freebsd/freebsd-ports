--- dot_parser.py.orig	2012-01-03 00:15:07 UTC
+++ dot_parser.py
@@ -25,7 +25,7 @@ from pyparsing import __version__ as pyp
 from pyparsing import ( nestedExpr, Literal, CaselessLiteral, Word, Upcase, OneOrMore, ZeroOrMore,
     Forward, NotAny, delimitedList, oneOf, Group, Optional, Combine, alphas, nums,
     restOfLine, cStyleComment, nums, alphanums, printables, empty, quotedString,
-    ParseException, ParseResults, CharsNotIn, _noncomma, dblQuotedString, QuotedString, ParserElement )
+    ParseException, ParseResults, CharsNotIn, dblQuotedString, QuotedString, ParserElement )
 
 
 class P_AttrList:
@@ -111,7 +111,7 @@ def push_top_graph_stmt(str, loc, toks):
             add_elements(g, element)
             
         else:
-            raise ValueError, "Unknown element statement: %r " % element
+            raise ValueError("Unknown element statement: %r " % element)
     
     
     for g in top_graphs:
@@ -218,14 +218,14 @@ def add_elements(g, toks, defaults_graph
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
@@ -267,7 +267,7 @@ def push_default_stmt(str, loc, toks):
     if default_type in ['graph', 'node', 'edge']:
         return DefaultStatement(default_type, attrs)
     else:
-        raise ValueError, "Unknown default statement: %r " % toks
+        raise ValueError("Unknown default statement: %r " % toks)
 
 
 def push_attr_list(str, loc, toks):
@@ -414,6 +414,7 @@ def graph_definition():
         
         double_quoted_string = QuotedString('"', multiline=True, unquoteResults=False) # dblQuotedString
 
+        _noncomma = "".join( [ c for c in printables if c != "," ] )
         alphastring_ = OneOrMore(CharsNotIn(_noncomma + ' '))
 
         def parse_html(s, loc, toks):
@@ -523,9 +524,9 @@ def parse_dot_data(data):
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
