--- packages/fpvectorial/src/fpvtocanvas.pas	2011/01/30 15:51:36	16850
+++ packages/fpvectorial/src/fpvtocanvas.pas	2011/06/17 09:52:19	17765
@@ -10,21 +10,30 @@
   Classes, SysUtils, Math,
   {$ifdef USE_LCL_CANVAS}
   Graphics, LCLIntf,
-  {$else}
-  fpcanvas,
   {$endif}
+  fpcanvas,
+  fpimage,
   fpvectorial;
 
 procedure DrawFPVectorialToCanvas(ASource: TvVectorialDocument;
-  {$ifdef USE_LCL_CANVAS}
-  ADest: TCanvas;
-  {$else}
   ADest: TFPCustomCanvas;
-  {$endif}
+  ADestX: Integer = 0; ADestY: Integer = 0; AMulX: Double = 1.0; AMulY: Double = 1.0);
+procedure DrawFPVPathToCanvas(ASource: TvVectorialDocument; CurPath: TPath;
+  ADest: TFPCustomCanvas;
+  ADestX: Integer = 0; ADestY: Integer = 0; AMulX: Double = 1.0; AMulY: Double = 1.0);
+procedure DrawFPVEntityToCanvas(ASource: TvVectorialDocument; CurEntity: TvEntity;
+  ADest: TFPCustomCanvas;
+  ADestX: Integer = 0; ADestY: Integer = 0; AMulX: Double = 1.0; AMulY: Double = 1.0);
+procedure DrawFPVTextToCanvas(ASource: TvVectorialDocument; CurText: TvText;
+  ADest: TFPCustomCanvas;
   ADestX: Integer = 0; ADestY: Integer = 0; AMulX: Double = 1.0; AMulY: Double = 1.0);
 
 implementation
 
+{$ifndef Windows}
+{$define FPVECTORIALDEBUG}
+{$endif}
+
 function Rotate2DPoint(P,Fix :TPoint; alpha:double): TPoint;
 var
   sinus, cosinus : Extended;
@@ -37,17 +46,16 @@
 end;
 
 procedure DrawRotatedEllipse(
-  {$ifdef USE_LCL_CANVAS}
-  ADest: TCanvas;
-  {$else}
   ADest: TFPCustomCanvas;
-  {$endif}
   CurEllipse: TvEllipse;
   ADestX: Integer = 0; ADestY: Integer = 0; AMulX: Double = 1.0; AMulY: Double = 1.0);
 var
   PointList: array[0..6] of TPoint;
   f: TPoint;
   dk, x1, x2, y1, y2: Integer;
+  {$ifdef USE_LCL_CANVAS}
+  ALCLDest: TCanvas absolute ADest;
+  {$endif}
 begin
   {$ifdef USE_LCL_CANVAS}
   CurEllipse.CalculateBoundingRectangle();
@@ -72,7 +80,7 @@
   // Conrollpoint of secondpart endpoint
   PointList[6] := PointList[0];   // Endpoint of
    // Back to the startpoint
-  ADest.PolyBezier(Pointlist[0]);
+  ALCLDest.PolyBezier(Pointlist[0]);
   {$endif}
 end;
 
@@ -90,15 +98,48 @@
 
   DrawFPVectorialToCanvas(ASource, ADest, 0, ASource.Height, 1.0, -1.0);
 }
+{.$define FPVECTORIAL_TOCANVAS_DEBUG}
 procedure DrawFPVectorialToCanvas(ASource: TvVectorialDocument;
-  {$ifdef USE_LCL_CANVAS}
-  ADest: TCanvas;
-  {$else}
   ADest: TFPCustomCanvas;
+  ADestX: Integer = 0; ADestY: Integer = 0; AMulX: Double = 1.0; AMulY: Double = 1.0);
+var
+  i: Integer;
+  CurEntity: TvEntity;
+begin
+  {$ifdef FPVECTORIAL_TOCANVAS_DEBUG}
+  WriteLn(':>DrawFPVectorialToCanvas');
+  {$endif}
+
+  for i := 0 to ASource.GetEntitiesCount - 1 do
+  begin
+    CurEntity := ASource.GetEntity(i);
+
+    if CurEntity is TPath then DrawFPVPathToCanvas(ASource, TPath(CurEntity), ADest, ADestX, ADestY, AMulX, AMulY)
+    else if CurEntity is TvText then DrawFPVTextToCanvas(ASource, TvText(CurEntity), ADest, ADestX, ADestY, AMulX, AMulY)
+    else DrawFPVEntityToCanvas(ASource, CurEntity, ADest, ADestX, ADestY, AMulX, AMulY);
+  end;
+
+  {$ifdef FPVECTORIALDEBUG}
+  WriteLn(':<DrawFPVectorialToCanvas');
   {$endif}
+end;
+
+procedure DrawFPVPathToCanvas(ASource: TvVectorialDocument; CurPath: TPath;
+  ADest: TFPCustomCanvas;
   ADestX: Integer = 0; ADestY: Integer = 0; AMulX: Double = 1.0; AMulY: Double = 1.0);
+
+  function CoordToCanvasX(ACoord: Double): Integer;
+  begin
+    Result := Round(ADestX + AmulX * ACoord);
+  end;
+
+  function CoordToCanvasY(ACoord: Double): Integer;
+  begin
+    Result := Round(ADestY + AmulY * ACoord);
+  end;
+
 var
-  i, j, k: Integer;
+  j, k: Integer;
   PosX, PosY: Integer; // Not modified by ADestX, etc
   CurSegment: TPathSegment;
   Cur2DSegment: T2DSegment absolute CurSegment;
@@ -107,123 +148,327 @@
   CurX, CurY: Integer; // Not modified by ADestX, etc
   CurveLength: Integer;
   t: Double;
-  // For text
-  CurText: TvText;
-  // For entities
-  CurEntity: TvEntity;
-  CurCircle: TvCircle;
-  CurEllipse: TvEllipse;
-  CurArc: TvCircularArc;
 begin
-  {$ifdef FPVECTORIALDEBUG}
-  WriteLn(':>DrawFPVectorialToCanvas');
-  {$endif}
-
   PosX := 0;
   PosY := 0;
+  ADest.Brush.Style := bsClear;
 
   ADest.MoveTo(ADestX, ADestY);
 
-  // Draws all paths
-  for i := 0 to ASource.PathCount - 1 do
+  CurPath.PrepareForSequentialReading;
+
+  // Set the path Pen and Brush options
+  ADest.Pen.Style := CurPath.Pen.Style;
+  ADest.Pen.Width := CurPath.Pen.Width;
+  ADest.Brush.Style := CurPath.Brush.Style;
+  ADest.Pen.FPColor := CurPath.Pen.Color;
+  ADest.Brush.FPColor := CurPath.Brush.Color;
+
+  {$ifdef FPVECTORIAL_TOCANVAS_DEBUG}
+  Write(Format('[Path] ID=%d', [i]));
+  {$endif}
+
+  for j := 0 to CurPath.Len - 1 do
   begin
-    //WriteLn('i = ', i);
-    ASource.Paths[i].PrepareForSequentialReading;
+    //WriteLn('j = ', j);
+    CurSegment := TPathSegment(CurPath.Next());
 
-    for j := 0 to ASource.Paths[i].Len - 1 do
+    case CurSegment.SegmentType of
+    stMoveTo:
+    begin
+      ADest.MoveTo(CoordToCanvasX(Cur2DSegment.X), CoordToCanvasY(Cur2DSegment.Y));
+      {$ifdef FPVECTORIAL_TOCANVAS_DEBUG}
+      Write(Format(' M%d,%d', [CoordToCanvasX(Cur2DSegment.X), CoordToCanvasY(Cur2DSegment.Y)]));
+      {$endif}
+    end;
+    // This element can override temporarely the Pen
+    st2DLineWithPen:
     begin
-      //WriteLn('j = ', j);
-      CurSegment := TPathSegment(ASource.Paths[i].Next());
+      ADest.Pen.FPColor := T2DSegmentWithPen(Cur2DSegment).Pen.Color;
 
-      case CurSegment.SegmentType of
-      stMoveTo:
-      begin
-        ADest.MoveTo(
-          Round(ADestX + AMulX * Cur2DSegment.X),
-          Round(ADestY + AMulY * Cur2DSegment.Y)
-          );
-      end;
-      st2DLine, st3DLine:
-      begin
-        ADest.LineTo(
-          Round(ADestX + AMulX * Cur2DSegment.X),
-          Round(ADestY + AMulY * Cur2DSegment.Y)
-          );
-      end;
-      { To draw a bezier we need to divide the interval in parts and make
-        lines between this parts }
-      st2DBezier, st3DBezier:
+      ADest.LineTo(CoordToCanvasX(Cur2DSegment.X), CoordToCanvasY(Cur2DSegment.Y));
+
+      ADest.Pen.FPColor := CurPath.Pen.Color;
+
+      {$ifdef FPVECTORIAL_TOCANVAS_DEBUG}
+      Write(Format(' L%d,%d', [CoordToCanvasX(Cur2DSegment.X), CoordToCanvasY(Cur2DSegment.Y)]));
+      {$endif}
+    end;
+    st2DLine, st3DLine:
+    begin
+      ADest.LineTo(CoordToCanvasX(Cur2DSegment.X), CoordToCanvasY(Cur2DSegment.Y));
+      {$ifdef FPVECTORIAL_TOCANVAS_DEBUG}
+      Write(Format(' L%d,%d', [CoordToCanvasX(Cur2DSegment.X), CoordToCanvasY(Cur2DSegment.Y)]));
+      {$endif}
+    end;
+    { To draw a bezier we need to divide the interval in parts and make
+      lines between this parts }
+    st2DBezier, st3DBezier:
+    begin
+      CurveLength :=
+        Round(sqrt(sqr(Cur2DBSegment.X3 - PosX) + sqr(Cur2DBSegment.Y3 - PosY))) +
+        Round(sqrt(sqr(Cur2DBSegment.X2 - Cur2DBSegment.X3) + sqr(Cur2DBSegment.Y2 - Cur2DBSegment.Y3))) +
+        Round(sqrt(sqr(Cur2DBSegment.X - Cur2DBSegment.X3) + sqr(Cur2DBSegment.Y - Cur2DBSegment.Y3)));
+
+      for k := 1 to CurveLength do
       begin
-        CurveLength :=
-          Round(sqrt(sqr(Cur2DBSegment.X3 - PosX) + sqr(Cur2DBSegment.Y3 - PosY))) +
-          Round(sqrt(sqr(Cur2DBSegment.X2 - Cur2DBSegment.X3) + sqr(Cur2DBSegment.Y2 - Cur2DBSegment.Y3))) +
-          Round(sqrt(sqr(Cur2DBSegment.X - Cur2DBSegment.X3) + sqr(Cur2DBSegment.Y - Cur2DBSegment.Y3)));
-
-        for k := 1 to CurveLength do
-        begin
-          t := k / CurveLength;
-          CurX := Round(sqr(1 - t) * (1 - t) * PosX + 3 * t * sqr(1 - t) * Cur2DBSegment.X2 + 3 * t * t * (1 - t) * Cur2DBSegment.X3 + t * t * t * Cur2DBSegment.X);
-          CurY := Round(sqr(1 - t) * (1 - t) * PosY + 3 * t * sqr(1 - t) * Cur2DBSegment.Y2 + 3 * t * t * (1 - t) * Cur2DBSegment.Y3 + t * t * t * Cur2DBSegment.Y);
-          ADest.LineTo(
-            Round(ADestX + AMulX * CurX),
-            Round(ADestY + AMulY * CurY));
-        end;
-        PosX := Round(Cur2DBSegment.X);
-        PosY := Round(Cur2DBSegment.Y);
-      end;
+        t := k / CurveLength;
+        CurX := Round(sqr(1 - t) * (1 - t) * PosX + 3 * t * sqr(1 - t) * Cur2DBSegment.X2 + 3 * t * t * (1 - t) * Cur2DBSegment.X3 + t * t * t * Cur2DBSegment.X);
+        CurY := Round(sqr(1 - t) * (1 - t) * PosY + 3 * t * sqr(1 - t) * Cur2DBSegment.Y2 + 3 * t * t * (1 - t) * Cur2DBSegment.Y3 + t * t * t * Cur2DBSegment.Y);
+        ADest.LineTo(CoordToCanvasX(CurX), CoordToCanvasY(CurY));
       end;
+      PosX := Round(Cur2DBSegment.X);
+      PosY := Round(Cur2DBSegment.Y);
+    end;
     end;
   end;
+  {$ifdef FPVECTORIAL_TOCANVAS_DEBUG}
+  WriteLn('');
+  {$endif}
+end;
+
+procedure DrawFPVEntityToCanvas(ASource: TvVectorialDocument; CurEntity: TvEntity;
+  ADest: TFPCustomCanvas;
+  ADestX: Integer = 0; ADestY: Integer = 0; AMulX: Double = 1.0; AMulY: Double = 1.0);
 
-  // Draws all entities
-  for i := 0 to ASource.GetEntityCount - 1 do
+  function CoordToCanvasX(ACoord: Double): Integer;
   begin
-    CurEntity := ASource.GetEntity(i);
-    if CurEntity is TvCircle then
+    Result := Round(ADestX + AmulX * ACoord);
+  end;
+
+  function CoordToCanvasY(ACoord: Double): Integer;
+  begin
+    Result := Round(ADestY + AmulY * ACoord);
+  end;
+
+var
+  i: Integer;
+  {$ifdef USE_LCL_CANVAS}
+  ALCLDest: TCanvas;
+  {$endif}
+  // For entities
+  CurCircle: TvCircle;
+  CurEllipse: TvEllipse;
+  //
+  CurArc: TvCircularArc;
+  FinalStartAngle, FinalEndAngle: double;
+  BoundsLeft, BoundsTop, BoundsRight, BoundsBottom,
+   IntStartAngle, IntAngleLength, IntTmp: Integer;
+  //
+  CurDim: TvAlignedDimension;
+  Points: array of TPoint;
+  UpperDim, LowerDim: T3DPoint;
+begin
+  {$ifdef USE_LCL_CANVAS}
+  ALCLDest := TCanvas(ADest);
+  {$endif}
+
+  ADest.Brush.Style := CurEntity.Brush.Style;
+  ADest.Pen.Style := CurEntity.Pen.Style;
+  ADest.Pen.FPColor := CurEntity.Pen.Color;
+  ADest.Brush.FPColor := CurEntity.Brush.Color;
+
+  if CurEntity is TvCircle then
+  begin
+    CurCircle := CurEntity as TvCircle;
+    ADest.Ellipse(
+      CoordToCanvasX(CurCircle.CenterX - CurCircle.Radius),
+      CoordToCanvasY(CurCircle.CenterY - CurCircle.Radius),
+      CoordToCanvasX(CurCircle.CenterX + CurCircle.Radius),
+      CoordToCanvasY(CurCircle.CenterY + CurCircle.Radius)
+      );
+  end
+  else if CurEntity is TvEllipse then
+  begin
+    CurEllipse := CurEntity as TvEllipse;
+    DrawRotatedEllipse(ADest, CurEllipse);
+  end
+  else if CurEntity is TvCircularArc then
+  begin
+    CurArc := CurEntity as TvCircularArc;
+    {$ifdef USE_LCL_CANVAS}
+    // ToDo: Consider a X axis inversion
+    // If the Y axis is inverted, then we need to mirror our angles as well
+    BoundsLeft := CoordToCanvasX(CurArc.CenterX - CurArc.Radius);
+    BoundsTop := CoordToCanvasY(CurArc.CenterY - CurArc.Radius);
+    BoundsRight := CoordToCanvasX(CurArc.CenterX + CurArc.Radius);
+    BoundsBottom := CoordToCanvasY(CurArc.CenterY + CurArc.Radius);
+    {if AMulY > 0 then
+    begin}
+      FinalStartAngle := CurArc.StartAngle;
+      FinalEndAngle := CurArc.EndAngle;
+    {end
+    else // AMulY is negative
     begin
-      CurCircle := CurEntity as TvCircle;
-      ADest.Ellipse(
-        Round(ADestX + AmulX * (CurCircle.CenterX - CurCircle.Radius)),
-        Round(ADestY + AMulY * (CurCircle.CenterY - CurCircle.Radius)),
-        Round(ADestX + AmulX * (CurCircle.CenterX + CurCircle.Radius)),
-        Round(ADestY + AMulY * (CurCircle.CenterY + CurCircle.Radius))
-        );
-    end
-    else if CurEntity is TvEllipse then
+      // Inverting the angles generates the correct result for Y axis inversion
+      if CurArc.EndAngle = 0 then FinalStartAngle := 0
+      else FinalStartAngle := 360 - 1* CurArc.EndAngle;
+      if CurArc.StartAngle = 0 then FinalEndAngle := 0
+      else FinalEndAngle := 360 - 1* CurArc.StartAngle;
+    end;}
+    IntStartAngle := Round(16*FinalStartAngle);
+    IntAngleLength := Round(16*(FinalEndAngle - FinalStartAngle));
+    // On Gtk2 and Carbon, the Left really needs to be to the Left of the Right position
+    // The same for the Top and Bottom
+    // On Windows it works fine either way
+    // On Gtk2 if the positions are inverted then the arcs are screwed up
+    // In Carbon if the positions are inverted, then the arc is inverted
+    if BoundsLeft > BoundsRight then
+    begin
+      IntTmp := BoundsLeft;
+      BoundsLeft := BoundsRight;
+      BoundsRight := IntTmp;
+    end;
+    if BoundsTop > BoundsBottom then
+    begin
+      IntTmp := BoundsTop;
+      BoundsTop := BoundsBottom;
+      BoundsBottom := IntTmp;
+    end;
+    // Arc(ALeft, ATop, ARight, ABottom, Angle16Deg, Angle16DegLength: Integer);
+    {$ifdef FPVECTORIALDEBUG}
+    WriteLn(Format('Drawing Arc Center=%f,%f Radius=%f StartAngle=%f AngleLength=%f',
+      [CurArc.CenterX, CurArc.CenterY, CurArc.Radius, IntStartAngle/16, IntAngleLength/16]));
+    {$endif}
+    ADest.Pen.FPColor := CurArc.Pen.Color;
+    ALCLDest.Arc(
+      BoundsLeft, BoundsTop, BoundsRight, BoundsBottom,
+      IntStartAngle, IntAngleLength
+      );
+    ADest.Pen.FPColor := colBlack;
+    // Debug info
+//      {$define FPVECTORIALDEBUG}
+//      {$ifdef FPVECTORIALDEBUG}
+//      WriteLn(Format('Drawing Arc x1y1=%d,%d x2y2=%d,%d start=%d end=%d',
+//        [BoundsLeft, BoundsTop, BoundsRight, BoundsBottom, IntStartAngle, IntAngleLength]));
+//      {$endif}
+{      ADest.TextOut(CoordToCanvasX(CurArc.CenterX), CoordToCanvasY(CurArc.CenterY),
+      Format('R=%d S=%d L=%d', [Round(CurArc.Radius*AMulX), Round(FinalStartAngle),
+      Abs(Round((FinalEndAngle - FinalStartAngle)))]));
+    ADest.Pen.Color := TColor($DDDDDD);
+    ADest.Rectangle(
+      BoundsLeft, BoundsTop, BoundsRight, BoundsBottom);
+    ADest.Pen.Color := clBlack;}
+    {$endif}
+  end
+  else if CurEntity is TvAlignedDimension then
+  begin
+    CurDim := CurEntity as TvAlignedDimension;
+    //
+    // Draws this shape:
+    // vertical     horizontal
+    // ___
+    // | |     or   ---| X cm
+    //   |           --|
+    // Which marks the dimension
+    ADest.MoveTo(CoordToCanvasX(CurDim.BaseRight.X), CoordToCanvasY(CurDim.BaseRight.Y));
+    ADest.LineTo(CoordToCanvasX(CurDim.DimensionRight.X), CoordToCanvasY(CurDim.DimensionRight.Y));
+    ADest.LineTo(CoordToCanvasX(CurDim.DimensionLeft.X), CoordToCanvasY(CurDim.DimensionLeft.Y));
+    ADest.LineTo(CoordToCanvasX(CurDim.BaseLeft.X), CoordToCanvasY(CurDim.BaseLeft.Y));
+    // Now the arrows
+    // horizontal
+    SetLength(Points, 3);
+    if CurDim.DimensionRight.Y = CurDim.DimensionLeft.Y then
     begin
-      CurEllipse := CurEntity as TvEllipse;
-      DrawRotatedEllipse(ADest, CurEllipse);
+      ADest.Brush.FPColor := colBlack;
+      ADest.Brush.Style := bsSolid;
+      // Left arrow
+      Points[0] := Point(CoordToCanvasX(CurDim.DimensionLeft.X), CoordToCanvasY(CurDim.DimensionLeft.Y));
+      Points[1] := Point(Points[0].X + 7, Points[0].Y - 3);
+      Points[2] := Point(Points[0].X + 7, Points[0].Y + 3);
+      ADest.Polygon(Points);
+      // Right arrow
+      Points[0] := Point(CoordToCanvasX(CurDim.DimensionRight.X), CoordToCanvasY(CurDim.DimensionRight.Y));
+      Points[1] := Point(Points[0].X - 7, Points[0].Y - 3);
+      Points[2] := Point(Points[0].X - 7, Points[0].Y + 3);
+      ADest.Polygon(Points);
+      ADest.Brush.Style := bsClear;
+      // Dimension text
+      Points[0].X := CoordToCanvasX((CurDim.DimensionLeft.X+CurDim.DimensionRight.X)/2);
+      Points[0].Y := CoordToCanvasY(CurDim.DimensionLeft.Y);
+      LowerDim.X := CurDim.DimensionRight.X-CurDim.DimensionLeft.X;
+      ADest.Font.Size := 10;
+      ADest.TextOut(Points[0].X, Points[0].Y, Format('%.1f', [LowerDim.X]));
     end
-    else if CurEntity is TvCircularArc then
+    else
     begin
-      CurArc := CurEntity as TvCircularArc;
-      {$ifdef USE_LCL_CANVAS}
-      // Arc(ALeft, ATop, ARight, ABottom, Angle16Deg, Angle16DegLength: Integer);
-      ADest.Arc(
-        Round(ADestX + AmulX * (CurArc.CenterX - CurArc.Radius)),
-        Round(ADestY + AmulY * (CurArc.CenterY - CurArc.Radius)),
-        Round(ADestX + AmulX * (CurArc.CenterX + CurArc.Radius)),
-        Round(ADestY + AmulY * (CurArc.CenterY + CurArc.Radius)),
-        Round(16*CurArc.StartAngle),
-        Round(16*CurArc.EndAngle - CurArc.StartAngle)
-        );
-      {$endif}
+      ADest.Brush.FPColor := colBlack;
+      ADest.Brush.Style := bsSolid;
+      // There is no upper/lower preference for DimensionLeft/Right, so we need to check
+      if CurDim.DimensionLeft.Y > CurDim.DimensionRight.Y then
+      begin
+        UpperDim := CurDim.DimensionLeft;
+        LowerDim := CurDim.DimensionRight;
+      end
+      else
+      begin
+        UpperDim := CurDim.DimensionRight;
+        LowerDim := CurDim.DimensionLeft;
+      end;
+      // Upper arrow
+      Points[0] := Point(CoordToCanvasX(UpperDim.X), CoordToCanvasY(UpperDim.Y));
+      Points[1] := Point(Points[0].X + Round(AMulX), Points[0].Y - Round(AMulY*3));
+      Points[2] := Point(Points[0].X - Round(AMulX), Points[0].Y - Round(AMulY*3));
+      ADest.Polygon(Points);
+      // Lower arrow
+      Points[0] := Point(CoordToCanvasX(LowerDim.X), CoordToCanvasY(LowerDim.Y));
+      Points[1] := Point(Points[0].X + Round(AMulX), Points[0].Y + Round(AMulY*3));
+      Points[2] := Point(Points[0].X - Round(AMulX), Points[0].Y + Round(AMulY*3));
+      ADest.Polygon(Points);
+      ADest.Brush.Style := bsClear;
+      // Dimension text
+      Points[0].X := CoordToCanvasX(CurDim.DimensionLeft.X);
+      Points[0].Y := CoordToCanvasY((CurDim.DimensionLeft.Y+CurDim.DimensionRight.Y)/2);
+      LowerDim.Y := CurDim.DimensionRight.Y-CurDim.DimensionLeft.Y;
+      if LowerDim.Y < 0 then LowerDim.Y := -1 * LowerDim.Y;
+      ADest.Font.Size := 10;
+      ADest.TextOut(Points[0].X, Points[0].Y, Format('%.1f', [LowerDim.Y]));
     end;
+    SetLength(Points, 0);
+{      // Debug info
+    ADest.TextOut(CoordToCanvasX(CurDim.BaseRight.X), CoordToCanvasY(CurDim.BaseRight.Y), 'BR');
+    ADest.TextOut(CoordToCanvasX(CurDim.DimensionRight.X), CoordToCanvasY(CurDim.DimensionRight.Y), 'DR');
+    ADest.TextOut(CoordToCanvasX(CurDim.DimensionLeft.X), CoordToCanvasY(CurDim.DimensionLeft.Y), 'DL');
+    ADest.TextOut(CoordToCanvasX(CurDim.BaseLeft.X), CoordToCanvasY(CurDim.BaseLeft.Y), 'BL');}
   end;
+end;
 
-  // Draws all text
-  for i := 0 to ASource.GetTextCount - 1 do
+procedure DrawFPVTextToCanvas(ASource: TvVectorialDocument; CurText: TvText;
+  ADest: TFPCustomCanvas;
+  ADestX: Integer = 0; ADestY: Integer = 0; AMulX: Double = 1.0; AMulY: Double = 1.0);
+
+  function CoordToCanvasX(ACoord: Double): Integer;
   begin
-    CurText := ASource.GetText(i);
-    ADest.Font.Height := Round(AmulY * CurText.FontSize);
-    ADest.Pen.Style := psSolid;
-    ADest.Pen.Color := clBlack;
-    ADest.TextOut(Round(CurText.X), Round(CurText.Y), CurText.Value);
+    Result := Round(ADestX + AmulX * ACoord);
   end;
 
-  {$ifdef FPVECTORIALDEBUG}
-  WriteLn(':<DrawFPVectorialToCanvas');
+  function CoordToCanvasY(ACoord: Double): Integer;
+  begin
+    Result := Round(ADestY + AmulY * ACoord);
+  end;
+
+var
+  i: Integer;
+  {$ifdef USE_LCL_CANVAS}
+  ALCLDest: TCanvas;
   {$endif}
+  //
+  LowerDim: T3DPoint;
+begin
+  {$ifdef USE_LCL_CANVAS}
+  ALCLDest := TCanvas(ADest);
+  {$endif}
+
+  ADest.Font.Size := Round(AmulX * CurText.Font.Size);
+  ADest.Pen.Style := psSolid;
+  ADest.Pen.FPColor := colBlack;
+  ADest.Brush.Style := bsClear;
+  {$ifdef USE_LCL_CANVAS}
+  ALCLDest.Font.Orientation := Round(CurText.Font.Orientation * 16);
+  {$endif}
+
+  LowerDim.Y := CurText.Y + CurText.Font.Size;
+  ADest.TextOut(CoordToCanvasX(CurText.X), CoordToCanvasY(LowerDim.Y), CurText.Value);
 end;
 
 end.
