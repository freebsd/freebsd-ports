--- lcl/interfaces/qt6/qtwidgets.pas.orig	2025-05-03 06:08:10 UTC
+++ lcl/interfaces/qt6/qtwidgets.pas
@@ -16497,10 +16497,6 @@ begin
     FActions.Free;
   end;
 
-  if Assigned(FActionHandle) then
-    QAction_Destroy(FActionHandle);
-  FActionHandle := nil;
-
   inherited Destroy;
 end;
 
@@ -16554,6 +16550,11 @@ begin
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
 
