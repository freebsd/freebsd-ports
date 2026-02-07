# Fix graphviz Python library API compatibility
#
# The memory-graph library uses outdated graphviz API from older versions.
# FreeBSD ports install py-graphviz 0.10.1 which changed the render() method:
#
# Old API (< 0.8):  graph.render(outfile=..., quiet=..., quiet_view=...)
# New API (>= 0.8): graph.render(filename=...) 
#
# The 'quiet' and 'quiet_view' parameters were deprecated and removed.
# This patch updates the API call to work with modern py-graphviz versions
# while maintaining all core functionality.
#
--- memory_graph/__init__.py.orig	2025-10-04 12:21:39.453707000 -0700
+++ memory_graph/__init__.py	2025-10-04 12:21:44.778850000 -0700
@@ -86,7 +86,7 @@
     if outfile.endswith('.gv') or outfile.endswith('.dot'):
         graph.save(filename=outfile)
     else:
-        graph.render(outfile=outfile, view=view, cleanup=False, quiet=False, quiet_view=False)
+        graph.render(filename=outfile, view=view, cleanup=False)
 
 
 def show(data, outfile=None, view=False, numbered = False):
