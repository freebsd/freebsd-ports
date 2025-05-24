--- qtwidgets.pas.orig	2025-05-23 12:42:39.954693000 -0700
+++ qtwidgets.pas	2025-05-23 12:44:46.183970000 -0700
@@ -16496,10 +16496,6 @@
 
     FActions.Free;
   end;
-
-  if Assigned(FActionHandle) then
-    QAction_Destroy(FActionHandle);
-  FActionHandle := nil;
 
   inherited Destroy;
 end;
@@ -16554,6 +16550,11 @@
     QMenu_hook_destroy(FAboutToHideHook);
     FAboutToHideHook := nil;
   end;
+
+  if Assigned(FActionHandle) then
+    QAction_Destroy(FActionHandle);
+  FActionHandle := nil;
+
   inherited DetachEvents;
 end;
 
