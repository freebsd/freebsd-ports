--- browsers/src/browsers-scripts.adb.orig	2014-05-23 17:24:28.000000000 +0000
+++ browsers/src/browsers-scripts.adb
@@ -70,27 +70,27 @@ package body Browsers.Scripts is
    P_Font_Color         : constant := 10;
    P_Font_LS            : constant := 11;
    P_Font_Halign        : constant := 12;
-   P_Font_Valign        : constant := 13;
-   P_Arrow_From_Head    : constant := 14;
-   P_Arrow_From_Length  : constant := 15;
-   P_Arrow_From_Angle   : constant := 16;
-   P_Arrow_From_Stroke  : constant := 17;
-   P_Arrow_From_Fill    : constant := 18;
-   P_Arrow_From_Width   : constant := 19;
-   P_Arrow_To_Head      : constant := 20;
-   P_Arrow_To_Length    : constant := 21;
-   P_Arrow_To_Angle     : constant := 22;
-   P_Arrow_To_Stroke    : constant := 23;
-   P_Arrow_To_Fill      : constant := 24;
-   P_Arrow_To_Width     : constant := 25;
-   P_Symbol_From_Name   : constant := 26;
-   P_Symbol_From_Stroke : constant := 27;
-   P_Symbol_From_Dist   : constant := 28;
-   P_Symbol_From_Width  : constant := 29;
-   P_Symbol_To_Name     : constant := 30;
-   P_Symbol_To_Stroke   : constant := 31;
-   P_Symbol_To_Dist     : constant := 32;
-   P_Symbol_To_Width    : constant := 33;
+   P_Arrow_From_Head    : constant := 13;
+   P_Arrow_From_Length  : constant := 14;
+   P_Arrow_From_Angle   : constant := 15;
+   P_Arrow_From_Stroke  : constant := 16;
+   P_Arrow_From_Fill    : constant := 17;
+   P_Arrow_From_Width   : constant := 18;
+   P_Arrow_To_Head      : constant := 19;
+   P_Arrow_To_Length    : constant := 20;
+   P_Arrow_To_Angle     : constant := 21;
+   P_Arrow_To_Stroke    : constant := 22;
+   P_Arrow_To_Fill      : constant := 23;
+   P_Arrow_To_Width     : constant := 24;
+   P_Symbol_From_Name   : constant := 25;
+   P_Symbol_From_Stroke : constant := 26;
+   P_Symbol_From_Dist   : constant := 27;
+   P_Symbol_From_Width  : constant := 28;
+   P_Symbol_To_Name     : constant := 29;
+   P_Symbol_To_Stroke   : constant := 30;
+   P_Symbol_To_Dist     : constant := 31;
+   P_Symbol_To_Width    : constant := 32;
+   P_Shadow_Color       : constant := 33;
    --  All the parameters to GPS.Browsers.Style.__init__
 
    PA_Item              : constant := 2;
@@ -1123,6 +1123,7 @@ package body Browsers.Scripts is
       M    : Margins := No_Margins;
       Item : Container_Item;
       X, Y : Gdouble := Gdouble'First;
+      AnchorX, AnchorY : Gdouble;
       Pos  : Gtkada.Style.Point;
    begin
       if Command = Constructor_Method then
@@ -1139,7 +1140,20 @@ package body Browsers.Scripts is
             Y := Gdouble (Nth_Arg (Data, 3, Float'First));
          end if;
 
-         Canvas_Item (Get_Item (Inst)).Set_Position ((X, Y));
+         AnchorX := Gdouble (Nth_Arg (Data, 4, 0.0));
+         AnchorY := Gdouble (Nth_Arg (Data, 5, 0.0));
+
+         Container_Item (Get_Item (Inst)).Set_Position
+           ((X, Y), Anchor_X => AnchorX, Anchor_Y => AnchorY);
+
+      elsif Command = "parent" then
+         Inst := Nth_Arg (Data, 1);
+         if Get_Item (Inst).Parent /= null then
+            Set_Return_Value
+               (Data,
+                Get_Instance (Python_Item_Access (Get_Item (Inst).Parent),
+                              Get_Script (Data)));
+         end if;
 
       elsif Command = "x" then
          Inst := Nth_Arg (Data, 1);
@@ -1383,9 +1397,10 @@ package body Browsers.Scripts is
                      Line_Spacing => Gint (Nth_Arg (Data, P_Font_LS, 0)),
                      Halign => Alignment'Val
                        (Integer'(Nth_Arg (Data, P_Font_Halign,
-                        Alignment'Pos (Pango_Align_Left)))),
-                     Valign => Gdouble (Nth_Arg (Data, P_Font_Valign, 0.0))
-                    ),
+                        Alignment'Pos (Pango_Align_Left))))),
+            Shadow     =>
+              (Color  => Color_From_Param (P_Shadow_Color, Null_RGBA),
+               others => <>),
             Arrow_From =>
               (Head  => Arrow_Head'Val
                  (Nth_Arg (Data, P_Arrow_From_Head, Arrow_Head'Pos (None))),
@@ -1713,7 +1728,6 @@ package body Browsers.Scripts is
             P_Font_Color         => Param ("fontColor", True),
             P_Font_LS            => Param ("fontLineSpacing", True),
             P_Font_Halign        => Param ("fontHalign", True),
-            P_Font_Valign        => Param ("fontValign", True),
             P_Arrow_From_Head    => Param ("arrowFrom", True),
             P_Arrow_From_Length  => Param ("arrowFromLength", True),
             P_Arrow_From_Angle   => Param ("arrowFromAngle", True),
@@ -1733,7 +1747,8 @@ package body Browsers.Scripts is
             P_Symbol_To_Name     => Param ("symbolTo", True),
             P_Symbol_To_Stroke   => Param ("symbolToStroke", True),
             P_Symbol_To_Dist     => Param ("symbolToDist", True),
-            P_Symbol_To_Width    => Param ("symbolToWidth", True)),
+            P_Symbol_To_Width    => Param ("symbolToWidth", True),
+            P_Shadow_Color       => Param ("shadowColor", True)),
          Class   => Style_Class,
          Handler => Style_Handler'Access);
 
@@ -1904,11 +1919,18 @@ package body Browsers.Scripts is
         (Kernel.Scripts,
          "set_position",
          Params  => (Param ("x", Optional => True),
-                     Param ("y", Optional => True)),
+                     Param ("y", Optional => True),
+                     Param ("anchorx", Optional => True),
+                     Param ("anchory", Optional => True)),
          Class   => Module.Item_Class,
          Handler => Item_Handler'Access);
       Register_Property
         (Kernel.Scripts,
+         "parent",
+         Class  => Module.Item_Class,
+         Getter => Item_Handler'Access);
+      Register_Property
+        (Kernel.Scripts,
          "x",
          Class  => Module.Item_Class,
          Getter => Item_Handler'Access);
