--- src_editor/src/src_editor_view.adb.orig	2012-07-02 09:23:20.000000000 +0000
+++ src_editor/src/src_editor_view.adb
@@ -1789,6 +1789,7 @@ package body Src_Editor_View is
    is
       View         : constant Source_View := Source_View (Widget);
       Dummy_Gint   : Gint;
+      Dummy2_Gint  : Gint;
       W, H, D      : Gint;
       Button_Y     : Gint;
       Lower, Upper : Gdouble;
@@ -1807,7 +1808,7 @@ package body Src_Editor_View is
          Button_Y := Gint (Get_Y (Event));
 
          Get_Geometry
-           (Get_Window (View.Area), Dummy_Gint, Dummy_Gint, W, H, D);
+           (Get_Window (View.Area), Dummy_Gint, Dummy2_Gint, W, H, D);
 
          Adj := Get_Vadjustment (View.Scroll);
          Lower := Get_Lower (Adj);
