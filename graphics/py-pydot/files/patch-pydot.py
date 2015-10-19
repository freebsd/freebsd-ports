--- pydot.py.orig	2012-01-03 00:15:07 UTC
+++ pydot.py
@@ -19,7 +19,7 @@ Distributed under MIT license [http://op
 
 __revision__ = "$LastChangedRevision$"
 __author__ = 'Ero Carrera'
-__version__ = '1.0.%d' % int( __revision__[21:-2] )
+__version__ = '1.0.28'
 __license__ = 'MIT'
 
 import os
@@ -29,8 +29,8 @@ import tempfile
 import copy
 try:
     import dot_parser
-except Exception, e:
-    print "Couldn't import dot_parser, loading of dot files will not be possible."
+except Exception as e:
+    print("Couldn't import dot_parser, loading of dot files will not be possible.")
     
 
 
@@ -92,7 +92,7 @@ CLUSTER_ATTRIBUTES = set( ['K', 'URL', '
 #
 class frozendict(dict):
     def _blocked_attribute(obj):
-        raise AttributeError, "A frozendict cannot be modified."
+        raise AttributeError("A frozendict cannot be modified.")
     _blocked_attribute = property(_blocked_attribute)
 
     __delitem__ = __setitem__ = clear = _blocked_attribute
@@ -190,7 +190,7 @@ def quote_if_necessary(s):
             return 'True'
         return 'False'
 
-    if not isinstance( s, basestring ):
+    if not isinstance( s, str ):
         return s
 
     if not s:
@@ -506,7 +506,7 @@ def find_graphviz():
                             #print "Used Windows registry"
                             return progs
                 
-                except Exception, excp:
+                except Exception as excp:
                     #raise excp
                     pass
                 else:
@@ -717,7 +717,7 @@ class InvocationException(Exception):
 
 
 
-class Node(object, Common):
+class Node(Common):
     """A graph node.
     
     This class represents a graph's node with all its attributes.
@@ -756,12 +756,12 @@ class Node(object, Common):
             # Remove the compass point
             #
             port = None
-            if isinstance(name, basestring) and not name.startswith('"'):
+            if isinstance(name, str) and not name.startswith('"'):
                 idx = name.find(':')
                 if idx > 0 and idx+1 < len(name):
                     name, port = name[:idx], name[idx:]
 
-            if isinstance(name, (long, int)):
+            if isinstance(name, int):
                 name = str(name)
             
             self.obj_dict['name'] = quote_if_necessary( name )
@@ -834,7 +834,7 @@ class Node(object, Common):
 
 
 
-class Edge(object,  Common ):
+class Edge(Common):
     """A graph edge.
     
     This class represents a graph's edge with all its attributes.
@@ -925,7 +925,7 @@ class Edge(object,  Common ):
         """
         
         if not isinstance(edge, Edge):
-            raise Error, "Can't compare and edge to a non-edge object."
+            raise Error("Can't compare and edge to a non-edge object.")
             
         if self.get_parent_graph().get_top_graph_type() == 'graph':
         
@@ -1025,7 +1025,7 @@ class Edge(object,  Common ):
     
     
     
-class Graph(object, Common):
+class Graph(Common):
     """Class representing a graph in Graphviz's dot language.
 
     This class implements the methods to work on a representation
@@ -1075,7 +1075,7 @@ class Graph(object, Common):
             self.obj_dict['attributes'] = dict(attrs)
             
             if graph_type not in ['graph', 'digraph']:
-                raise Error, 'Invalid type "%s". Accepted graph types are: graph, digraph, subgraph' % graph_type
+                raise Error('Invalid type "%s". Accepted graph types are: graph, digraph, subgraph' % graph_type)
     
     
             self.obj_dict['name'] = quote_if_necessary(graph_name)
@@ -2022,7 +2022,7 @@ class Dot(Graph):
                 'Program terminated with status: %d. stderr follows: %s' % (
                     status, stderr_output) )
         elif stderr_output:
-            print stderr_output
+            print(stderr_output)
         
         # For each of the image files...
         #
