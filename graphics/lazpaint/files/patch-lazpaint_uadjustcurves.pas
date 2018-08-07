--- lazpaint/uadjustcurves.pas	2018-04-25 23:53:59.146788000 -0500
+++ lazpaint/uadjustcurves.pas	2018-04-25 23:57:23.786990000 -0500
@@ -156,8 +156,8 @@
   begin
       with CoordToBitmap(i/FNbGrid,i/FNbGrid) do
       begin
-        Bitmap.DrawLineAntialias(round(FPoint0.x),round(y),Bitmap.Width,round(y),FGridColor,BGRAPixelTransparent,FTickSize,false);
-        Bitmap.DrawLineAntialias(round(x),round(FPoint0.y),round(x),0,FGridColor,BGRAPixelTransparent,FTickSize,false);
+        Bitmap.DrawLineAntialias(System.round(FPoint0.x),System.round(y),Bitmap.Width,System.round(y),FGridColor,BGRAPixelTransparent,FTickSize,false);
+        Bitmap.DrawLineAntialias(System.round(x),System.round(FPoint0.y),System.round(x),0,FGridColor,BGRAPixelTransparent,FTickSize,false);
       end;
   end;
   curve := SelectedCurve;
@@ -515,14 +515,14 @@
     with GetCoord(0,i/high(labels)) do
     begin
       Bitmap.TextOut(x-FTickSize,y-th div 2,labels[i],axesColor,taRightJustify);
-      Bitmap.DrawLine(round(x),round(y),round(x-FTickSize),round(y),axesColor,False);
+      Bitmap.DrawLine(System.round(x),System.round(y),System.round(x-FTickSize),System.round(y),axesColor,False);
     end;
     with GetCoord(i/high(labels),0) do
     begin
       if i = 0 then
         Bitmap.TextOut(x,y+FTickSize,labels[i],axesColor,taLeftJustify) else
         Bitmap.TextOut(x,y+FTickSize,labels[i],axesColor,taCenter);
-      Bitmap.DrawLine(round(x),round(y),round(x),round(y+FTickSize),axesColor,False);
+      Bitmap.DrawLine(System.round(x),System.round(y),System.round(x),System.round(y+FTickSize),axesColor,False);
     end;
   end;
   Bitmap.DrawLine(leftMargin, 0, leftMargin, Bitmap.Height - bottomMargin, axesColor, False);
