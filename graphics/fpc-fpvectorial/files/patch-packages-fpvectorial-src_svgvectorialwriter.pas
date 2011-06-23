--- packages/fpvectorial/src/svgvectorialwriter.pas	2011/01/14 14:45:03	16765
+++ packages/fpvectorial/src/svgvectorialwriter.pas	2011/06/17 09:52:19	17765
@@ -13,7 +13,7 @@
 interface
 
 uses
-  Classes, SysUtils, math, fpvectorial;
+  Classes, SysUtils, math, fpvectorial, fpvutils, fpcanvas;
 
 type
   { TvSVGVectorialWriter }
@@ -23,8 +23,9 @@
     FPointSeparator, FCommaSeparator: TFormatSettings;
     procedure WriteDocumentSize(AStrings: TStrings; AData: TvVectorialDocument);
     procedure WriteDocumentName(AStrings: TStrings; AData: TvVectorialDocument);
-    procedure WritePaths(AStrings: TStrings; AData: TvVectorialDocument);
-    procedure WriteTexts(AStrings: TStrings; AData: TvVectorialDocument);
+    procedure WritePath(AIndex: Integer; APath: TPath; AStrings: TStrings; AData: TvVectorialDocument);
+    procedure WriteText(AStrings: TStrings; lText: TvText; AData: TvVectorialDocument);
+    procedure WriteEntities(AStrings: TStrings; AData: TvVectorialDocument);
     procedure ConvertFPVCoordinatesToSVGCoordinates(
       const AData: TvVectorialDocument;
       const ASrcX, ASrcY: Double; var ADestX, ADestY: double);
@@ -74,90 +75,106 @@
   SVG uses commas "," to separate the X,Y coordinates, so it always uses points
   "." as decimal separators and uses no thousand separators
 }
-procedure TvSVGVectorialWriter.WritePaths(AStrings: TStrings; AData: TvVectorialDocument);
+procedure TvSVGVectorialWriter.WritePath(AIndex: Integer; APath: TPath; AStrings: TStrings;
+  AData: TvVectorialDocument);
 var
-  i, j: Integer;
+  j: Integer;
   PathStr: string;
-  lPath: TPath;
   PtX, PtY, OldPtX, OldPtY: double;
   BezierCP1X, BezierCP1Y, BezierCP2X, BezierCP2Y: double;
   segment: TPathSegment;
   l2DSegment: T2DSegment absolute segment;
   l2DBSegment: T2DBezierSegment absolute segment;
+  // Pen properties
+  lPenWidth: Integer;
+  lPenColor: string;
+  // Brush properties
+  lFillColor: string;
 begin
-  for i := 0 to AData.GetPathCount() - 1 do
-  begin
-    OldPtX := 0;
-    OldPtY := 0;
+  OldPtX := 0;
+  OldPtY := 0;
+  PathStr := '';
 
-    PathStr := '';
-    lPath := AData.GetPath(i);
-    lPath.PrepareForSequentialReading;
+  APath.PrepareForSequentialReading();
 
-    for j := 0 to lPath.Len - 1 do
-    begin
-      segment := TPathSegment(lPath.Next());
+  for j := 0 to APath.Len - 1 do
+  begin
+    segment := TPathSegment(APath.Next());
+
+    if (segment.SegmentType <> st2DLine)
+      and (segment.SegmentType <> stMoveTo)
+      and (segment.SegmentType <> st2DBezier)
+      then Break; // unsupported line type
 
-      if (segment.SegmentType <> st2DLine)
-        and (segment.SegmentType <> stMoveTo)
-        and (segment.SegmentType <> st2DBezier)
-        then Break; // unsupported line type
+    // Coordinate conversion from fpvectorial to SVG
+    ConvertFPVCoordinatesToSVGCoordinates(
+      AData, l2DSegment.X, l2DSegment.Y, PtX, PtY);
+    PtX := PtX - OldPtX;
+    PtY := PtY - OldPtY;
 
-      // Coordinate conversion from fpvectorial to SVG
+    if (segment.SegmentType = stMoveTo) then
+    begin
+      PathStr := PathStr + 'm '
+        + FloatToStr(PtX, FPointSeparator) + ','
+        + FloatToStr(PtY, FPointSeparator) + ' ';
+    end
+    else if (segment.SegmentType = st2DLine) then
+    begin
+      PathStr := PathStr + 'l '
+        + FloatToStr(PtX, FPointSeparator) + ','
+        + FloatToStr(PtY, FPointSeparator) + ' ';
+    end
+    else if (segment.SegmentType = st2DBezier) then
+    begin
+      // Converts all coordinates to absolute values
       ConvertFPVCoordinatesToSVGCoordinates(
-        AData, l2DSegment.X, l2DSegment.Y, PtX, PtY);
-      PtX := PtX - OldPtX;
-      PtY := PtY - OldPtY;
-
-      if (segment.SegmentType = stMoveTo) then
-      begin
-        PathStr := PathStr + 'm '
-          + FloatToStr(PtX, FPointSeparator) + ','
-          + FloatToStr(PtY, FPointSeparator) + ' ';
-      end
-      else if (segment.SegmentType = st2DLine) then
-      begin
-        PathStr := PathStr + 'l '
-          + FloatToStr(PtX, FPointSeparator) + ','
-          + FloatToStr(PtY, FPointSeparator) + ' ';
-      end
-      else if (segment.SegmentType = st2DBezier) then
-      begin
-        // Converts all coordinates to absolute values
-        ConvertFPVCoordinatesToSVGCoordinates(
-          AData, l2DBSegment.X2, l2DBSegment.Y2, BezierCP1X, BezierCP1Y);
-        ConvertFPVCoordinatesToSVGCoordinates(
-          AData, l2DBSegment.X3, l2DBSegment.Y3, BezierCP2X, BezierCP2Y);
-
-        // Transforms them into values relative to the initial point
-        BezierCP1X := BezierCP1X - OldPtX;
-        BezierCP1Y := BezierCP1Y - OldPtY;
-        BezierCP2X := BezierCP2X - OldPtX;
-        BezierCP2Y := BezierCP2Y - OldPtY;
-
-        // PtX and PtY already contains the destination point
-
-        // Now render our 2D cubic bezier
-        PathStr := PathStr + 'c '
-          + FloatToStr(BezierCP1X, FPointSeparator) + ','
-          + FloatToStr(BezierCP1Y, FPointSeparator) + ' '
-          + FloatToStr(BezierCP2X, FPointSeparator) + ','
-          + FloatToStr(BezierCP2Y, FPointSeparator) + ' '
-          + FloatToStr(PtX, FPointSeparator) + ','
-          + FloatToStr(PtY, FPointSeparator) + ' '
-          ;
-      end;
-
-      // Store the current position for future points
-      OldPtX := OldPtX + PtX;
-      OldPtY := OldPtY + PtY;
+        AData, l2DBSegment.X2, l2DBSegment.Y2, BezierCP1X, BezierCP1Y);
+      ConvertFPVCoordinatesToSVGCoordinates(
+        AData, l2DBSegment.X3, l2DBSegment.Y3, BezierCP2X, BezierCP2Y);
+
+      // Transforms them into values relative to the initial point
+      BezierCP1X := BezierCP1X - OldPtX;
+      BezierCP1Y := BezierCP1Y - OldPtY;
+      BezierCP2X := BezierCP2X - OldPtX;
+      BezierCP2Y := BezierCP2Y - OldPtY;
+
+      // PtX and PtY already contains the destination point
+
+      // Now render our 2D cubic bezier
+      PathStr := PathStr + 'c '
+        + FloatToStr(BezierCP1X, FPointSeparator) + ','
+        + FloatToStr(BezierCP1Y, FPointSeparator) + ' '
+        + FloatToStr(BezierCP2X, FPointSeparator) + ','
+        + FloatToStr(BezierCP2Y, FPointSeparator) + ' '
+        + FloatToStr(PtX, FPointSeparator) + ','
+        + FloatToStr(PtY, FPointSeparator) + ' '
+        ;
     end;
 
-    AStrings.Add('  <path');
-    AStrings.Add('    style="fill:none;stroke:#000000;stroke-width:1px;stroke-linecap:butt;stroke-linejoin:miter;stroke-opacity:1"');
-    AStrings.Add('    d="' + PathStr + '"');
-    AStrings.Add('  id="path' + IntToStr(i) + '" />');
+    // Store the current position for future points
+    OldPtX := OldPtX + PtX;
+    OldPtY := OldPtY + PtY;
   end;
+
+  // Get the Pen Width
+  if APath.Pen.Width >= 1 then lPenWidth := APath.Pen.Width
+  else lPenWidth := 1;
+
+  // Get the Pen Color and Style
+  if APath.Pen.Style = psClear then lPenColor := 'none'
+  else lPenColor := '#' + FPColorToRGBHexString(APath.Pen.Color);
+
+  // Get the Brush color and style
+  if APath.Brush.Style = bsClear then lFillColor := 'none'
+  else lFillColor := '#' + FPColorToRGBHexString(APath.Brush.Color);
+
+  // Now effectively write the path
+  AStrings.Add('  <path');
+  AStrings.Add(Format('    style="fill:%s;stroke:%s;stroke-width:%dpx;'
+   + 'stroke-linecap:butt;stroke-linejoin:miter;stroke-opacity:1"',
+   [lFillColor, lPenColor, lPenWidth]));
+  AStrings.Add('    d="' + PathStr + '"');
+  AStrings.Add('  id="path' + IntToStr(AIndex) + '" />');
 end;
 
 procedure TvSVGVectorialWriter.ConvertFPVCoordinatesToSVGCoordinates(
@@ -197,43 +214,52 @@
 
   // Now data
   AStrings.Add('  <g id="layer1">');
-  WritePaths(AStrings, AData);
-  WriteTexts(AStrings, AData);
+  WriteEntities(AStrings, AData);
   AStrings.Add('  </g>');
 
   // finalization
   AStrings.Add('</svg>');
 end;
 
-procedure TvSVGVectorialWriter.WriteTexts(AStrings: TStrings; AData: TvVectorialDocument);
+procedure TvSVGVectorialWriter.WriteText(AStrings: TStrings; lText: TvText; AData: TvVectorialDocument);
 var
   i, j, FontSize: Integer;
   TextStr, FontName, SVGFontFamily: string;
-  lText: TvText;
   PtX, PtY: double;
 begin
-  for i := 0 to AData.GetTextCount() - 1 do
-  begin
-    TextStr := '';
-    lText := AData.GetText(i);
+  TextStr := '';
 
-    ConvertFPVCoordinatesToSVGCoordinates(
-        AData, lText.X, lText.Y, PtX, PtY);
+  ConvertFPVCoordinatesToSVGCoordinates(
+      AData, lText.X, lText.Y, PtX, PtY);
 
-    TextStr := lText.Value;
-    FontSize:= ceil(lText.FontSize / FLOAT_MILIMETERS_PER_PIXEL);
-    SVGFontFamily := 'Arial, sans-serif';//lText.FontName;
-
-    AStrings.Add('  <text ');
-    AStrings.Add('    x="' + FloatToStr(PtX, FPointSeparator) + '"');
-    AStrings.Add('    y="' + FloatToStr(PtY, FPointSeparator) + '"');
+  TextStr := lText.Value;
+  FontSize:= ceil(lText.Font.Size / FLOAT_MILIMETERS_PER_PIXEL);
+  SVGFontFamily := 'Arial, sans-serif';//lText.FontName;
+
+  AStrings.Add('  <text ');
+  AStrings.Add('    x="' + FloatToStr(PtX, FPointSeparator) + '"');
+  AStrings.Add('    y="' + FloatToStr(PtY, FPointSeparator) + '"');
 //    AStrings.Add('    font-size="' + IntToStr(FontSize) + '"'); Doesn't seam to work, we need to use the tspan
-    AStrings.Add('    font-family="' + SVGFontFamily + '">');
-    AStrings.Add('    <tspan ');
-    AStrings.Add('      style="font-size:' + IntToStr(FontSize) + '" ');
+  AStrings.Add('    font-family="' + SVGFontFamily + '">');
+  AStrings.Add('    <tspan ');
+  AStrings.Add('      style="font-size:' + IntToStr(FontSize) + '" ');
 //    AStrings.Add('      id="tspan2828" ');
-    AStrings.Add('    >');
-    AStrings.Add(TextStr + '</tspan></text>');
+  AStrings.Add('    >');
+  AStrings.Add(TextStr + '</tspan></text>');
+end;
+
+procedure TvSVGVectorialWriter.WriteEntities(AStrings: TStrings;
+  AData: TvVectorialDocument);
+var
+  lEntity: TvEntity;
+  i: Integer;
+begin
+  for i := 0 to AData.GetEntitiesCount() - 1 do
+  begin
+    lEntity := AData.GetEntity(i);
+
+    if lEntity is TPath then WritePath(i, TPath(lEntity), AStrings, AData)
+    else if lEntity is TvText then WriteText(AStrings, TvText(lEntity), AData);
   end;
 end;
 
