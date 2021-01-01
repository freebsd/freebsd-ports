--- node_modules/tree-view/spec/tree-view-package-spec.coffee.orig	2019-12-27 06:42:40 UTC
+++ node_modules/tree-view/spec/tree-view-package-spec.coffee
@@ -5054,7 +5054,7 @@ describe "TreeView", ->
         treeView.rootDragAndDrop.onDragStart(dragStartEvent)
 
         expect(dragStartEvent.dataTransfer.getData("text/plain")).toEqual gammaDirPath
-        if process.platform in ['darwin', 'linux']
+        if process.platform in ['darwin', 'linux', 'freebsd']
           expect(dragStartEvent.dataTransfer.getData("text/uri-list")).toEqual "file://#{gammaDirPath}"
 
     describe "when a root folder is dropped from another Atom window", ->
