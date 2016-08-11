--- pydot.py.orig	2016-05-24 09:57:52.000000000 +0800
+++ pydot.py	2016-05-28 01:22:15.617300969 +0800
@@ -29,7 +29,7 @@
 import warnings
 try:
     import dot_parser
-except Exception, e:
+except Exception as e:
     warnings.warn(
         "Couldn't import dot_parser, "
         "loading of dot files will not be possible.")
@@ -94,7 +94,7 @@
 #
 class frozendict(dict):
     def _blocked_attribute(obj):
-        raise AttributeError, "A frozendict cannot be modified."
+        raise AttributeError("A frozendict cannot be modified.")
     _blocked_attribute = property(_blocked_attribute)
 
     __delitem__ = __setitem__ = clear = _blocked_attribute
@@ -192,7 +192,7 @@
             return 'True'
         return 'False'
 
-    if not isinstance( s, basestring ):
+    if not isinstance( s, str ):
         return s
 
     if not s:
@@ -505,10 +505,10 @@
                         path = os.path.join(path, "bin")
                         progs = __find_executables(path)
                         if progs is not None :
-                            #print "Used Windows registry"
+                            #print("Used Windows registry")
                             return progs
 
-                except Exception, excp:
+                except Exception as excp:
                     #raise excp
                     pass
                 else:
@@ -523,7 +523,7 @@
         for path in os.environ['PATH'].split(os.pathsep):
             progs = __find_executables(path)
             if progs is not None :
-                #print "Used path"
+                #print("Used path")
                 return progs
 
     # Method 3 (Windows only)
@@ -550,7 +550,7 @@
 
         if progs is not None :
 
-            #print "Used default install location"
+            #print("Used default install location")
             return progs
 
 
@@ -562,7 +562,7 @@
 
         progs = __find_executables(path)
         if progs is not None :
-            #print "Used path"
+            #print("Used path")
             return progs
 
     # Failed to find GraphViz
@@ -719,7 +719,7 @@
 
 
 
-class Node(object, Common):
+class Node(Common):
     """A graph node.
 
     This class represents a graph's node with all its attributes.
@@ -758,12 +758,12 @@
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
 
             self.obj_dict['name'] = quote_if_necessary(name)
@@ -836,7 +836,7 @@
 
 
 
-class Edge(object,  Common ):
+class Edge(Common):
     """A graph edge.
 
     This class represents a graph's edge with all its attributes.
@@ -927,7 +927,7 @@
         """
 
         if not isinstance(edge, Edge):
-            raise Error, "Can't compare and edge to a non-edge object."
+            raise Error("Can't compare and edge to a non-edge object.")
 
         if self.get_parent_graph().get_top_graph_type() == 'graph':
 
@@ -1027,7 +1027,7 @@
 
 
 
-class Graph(object, Common):
+class Graph(Common):
     """Class representing a graph in Graphviz's dot language.
 
     This class implements the methods to work on a representation
@@ -1077,7 +1077,7 @@
             self.obj_dict['attributes'] = dict(attrs)
 
             if graph_type not in ['graph', 'digraph']:
-                raise Error, 'Invalid type "%s". Accepted graph types are: graph, digraph' % graph_type
+                raise Error('Invalid type "%s". Accepted graph types are: graph, digraph' % graph_type)
 
 
             self.obj_dict['name'] = quote_if_necessary(graph_name)
@@ -2024,7 +2024,7 @@
                 'Program terminated with status: %d. stderr follows: %s' % (
                     status, stderr_output) )
         elif stderr_output:
-            print stderr_output
+            print(stderr_output)
 
         # For each of the image files...
         #
