--- ./xlgui/panel/collection.py.orig	2009-05-27 11:09:52.000000000 -0400
+++ ./xlgui/panel/collection.py	2009-06-15 22:11:40.632786042 -0400
@@ -223,11 +223,7 @@
             self.menu.popup(event)
 
     def on_expanded(self, tree, iter, path):
-        if self.model.iter_n_children(iter) == 1 and \
-            self.model.get_value(self.model.iter_children(iter), 1) == None:
-            iter_sep = self.model.iter_children(iter)
-            self.load_subtree(iter)
-            self.model.remove(iter_sep)
+        self.load_subtree(iter)
 
     def get_node_keywords(self, parent):
         if not parent:
@@ -290,10 +286,16 @@
         self.controller.main.update_track_counts()
 
     def load_subtree(self, parent):
+        iter_sep = None
         if parent == None:
             depth = 0
         else:
-            depth = self.model.iter_depth(parent) +1
+            if self.model.iter_n_children(parent) != 1 or \
+                self.model.get_value(self.model.iter_children(parent), 1) != None:
+                return
+            iter_sep = self.model.iter_children(parent)
+            depth = self.model.iter_depth(parent) + 1
+
         terms = self.get_node_search_terms(parent)
         if terms:
             search = " ".join(terms)
@@ -377,3 +379,6 @@
             iter = self.model.append(parent, [image, v, None])
             if not bottom:
                 self.model.append(iter, [None, None, None])
+
+        if iter_sep is not None:
+            self.model.remove(iter_sep)
