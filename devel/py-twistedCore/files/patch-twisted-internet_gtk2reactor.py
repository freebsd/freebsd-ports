--- twisted/internet/gtk2reactor.py.orig	2012-07-03 21:24:23.000000000 +0400
+++ twisted/internet/gtk2reactor.py	2012-07-03 21:24:45.000000000 +0400
@@ -27,7 +27,7 @@
     ["gi"],
     "Introspected and static glib/gtk bindings must not be mixed; can't "
     "import gtk2reactor since gi module is already imported.",
-    preventImports=["gi"])
+    preventImports=[""])
 
 try:
     if not hasattr(sys, 'frozen'):
