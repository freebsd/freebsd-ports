--- node_modules/tree-view/lib/root-drag-and-drop.coffee.orig	2019-05-14 21:29:00 UTC
+++ node_modules/tree-view/lib/root-drag-and-drop.coffee
@@ -42,7 +42,7 @@ class RootDragAndDropHandler
 
     e.dataTransfer.setData 'text/plain', directory.path
 
-    if process.platform in ['darwin', 'linux']
+    if process.platform in ['darwin', 'linux', 'freebsd']
       pathUri = "file://#{directory.path}" unless @uriHasProtocol(directory.path)
       e.dataTransfer.setData 'text/uri-list', pathUri
 
