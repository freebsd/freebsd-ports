--- packages/fpvectorial/src/fpvectorial.pas	2011/01/30 15:51:36	16850
+++ packages/fpvectorial/src/fpvectorial.pas	2011/06/17 09:52:19	17765
@@ -18,14 +18,17 @@
 interface
 
 uses
-  Classes, SysUtils, Math;
+  Classes, SysUtils, Math,
+  fpcanvas, fpimage;
 
 type
   TvVectorialFormat = (
     { Multi-purpose document formats }
-    vfPDF, vfPostScript, vfSVG, vfCorelDrawCDR, vfWindowsMetafileWMF,
+    vfPDF, vfSVG, vfCorelDrawCDR, vfWindowsMetafileWMF,
     { CAD formats }
     vfDXF,
+    { Printing formats }
+    vfPostScript, vfEncapsulatedPostScript,
     { GCode formats }
     vfGCodeAvisoCNCPrototipoV5, vfGCodeAvisoCNCPrototipoV6);
 
@@ -37,10 +40,45 @@
   STR_SVG_EXTENSION = '.svg';
   STR_CORELDRAW_EXTENSION = '.cdr';
   STR_WINMETAFILE_EXTENSION = '.wmf';
+  STR_AUTOCAD_EXCHANGE_EXTENSION = '.dxf';
+  STR_ENCAPSULATEDPOSTSCRIPT_EXTENSION = '.eps';
 
 type
+  { Pen, Brush and Font }
+
+  TvPen = record
+    Color: TFPColor;
+    Style: TFPPenStyle;
+    Width: Integer;
+  end;
+
+  TvBrush = record
+    Color: TFPColor;
+    Style: TFPBrushStyle;
+  end;
+
+  TvFont = record
+    Color: TFPColor;
+    Size: integer;
+    Name: utf8string;
+    {@@
+      Font orientation is measured in degrees and uses the
+      same direction as the LCL TFont.orientation, which is counter-clockwise.
+      Zero is the normal, horizontal, orientation.
+    }
+    Orientation: Double;
+  end;
+
+  { Coordinates and polyline segments }
+
+  T3DPoint = record
+    X, Y, Z: Double;
+  end;
+
+  P3DPoint = ^T3DPoint;
+
   TSegmentType = (
-    st2DLine, st2DBezier,
+    st2DLine, st2DLineWithPen, st2DBezier,
     st3DLine, st3DBezier, stMoveTo);
 
   {@@
@@ -70,6 +108,11 @@
     X, Y: Double;
   end;
 
+  T2DSegmentWithPen = class(T2DSegment)
+  public
+    Pen: TvPen;
+  end;
+
   {@@
     In Bezier segments, we remain using the X and Y coordinates for the ending point.
     The starting point is where the previous segment ended, so that the intermediary
@@ -96,13 +139,30 @@
     X3, Y3, Z3: Double;
   end;
 
-  TPath = class
+  { Now all elements }
+
+  {@@
+    All elements should derive from TvEntity, regardless of whatever properties
+    they might contain.
+  }
+
+  TvEntity = class
+  public
+    {@@ The global Pen for the entire entity. In the case of paths, individual
+        elements might be able to override this setting. }
+    Pen: TvPen;
+    {@@ The global Brush for the entire entity. In the case of paths, individual
+        elements might be able to override this setting. }
+    Brush: TvBrush;
+    constructor Create; virtual;
+  end;
+
+  TPath = class(TvEntity)
     Len: Integer;
     Points: TPathSegment; // Beginning of the double-linked list
     PointsEnd: TPathSegment; // End of the double-linked list
     CurPoint: TPathSegment; // Used in PrepareForSequentialReading and Next
-    procedure Assign(APath: TPath);
-    function Count(): TPathSegment;
+    procedure Assign(ASource: TPath);
     procedure PrepareForSequentialReading;
     function Next(): TPathSegment;
   end;
@@ -113,18 +173,11 @@
     At the moment fonts are unsupported, only simple texts
     up to 255 chars are supported.
   }
-  TvText = class
+  TvText = class(TvEntity)
   public
     X, Y, Z: Double; // Z is ignored in 2D formats
-    FontSize: integer;
-    FontName: utf8string;
     Value: utf8string;
-  end;
-
-  {@@
-  }
-  TvEntity = class
-  public
+    Font: TvFont;
   end;
 
   {@@
@@ -145,9 +198,6 @@
 
   {@@
   }
-
-  { TvEllipse }
-
   TvEllipse = class(TvEntity)
   public
     // Mandatory fields
@@ -159,6 +209,24 @@
     procedure CalculateBoundingRectangle;
   end;
 
+  {@@
+   The brush has no effect in this class
+
+   DimensionLeft ---text--- DimensionRight
+                 |        |
+                 |        | BaseRight
+                 |
+                 | BaseLeft
+  }
+
+  { TvAlignedDimension }
+
+  TvAlignedDimension = class(TvEntity)
+  public
+    // Mandatory fields
+    BaseLeft, BaseRight, DimensionLeft, DimensionRight: T3DPoint;
+  end;
+
 type
 
   TvCustomVectorialWriter = class;
@@ -168,8 +236,6 @@
 
   TvVectorialDocument = class
   private
-    FPaths: TFPList;
-    FTexts: TFPList;
     FEntities: TFPList;
     FTmpPath: TPath;
     FTmpText: TvText;
@@ -184,10 +250,14 @@
     { Base methods }
     constructor Create;
     destructor Destroy; override;
-    procedure WriteToFile(AFileName: string; AFormat: TvVectorialFormat);
+    procedure Assign(ASource: TvVectorialDocument);
+    procedure AssignTo(ADest: TvVectorialDocument);
+    procedure WriteToFile(AFileName: string; AFormat: TvVectorialFormat); overload;
+    procedure WriteToFile(AFileName: string); overload;
     procedure WriteToStream(AStream: TStream; AFormat: TvVectorialFormat);
     procedure WriteToStrings(AStrings: TStrings; AFormat: TvVectorialFormat);
-    procedure ReadFromFile(AFileName: string; AFormat: TvVectorialFormat);
+    procedure ReadFromFile(AFileName: string; AFormat: TvVectorialFormat); overload;
+    procedure ReadFromFile(AFileName: string); overload;
     procedure ReadFromStream(AStream: TStream; AFormat: TvVectorialFormat);
     procedure ReadFromStrings(AStrings: TStrings; AFormat: TvVectorialFormat);
     class function GetFormatFromExtension(AFileName: string): TvVectorialFormat;
@@ -195,27 +265,35 @@
     { Data reading methods }
     function  GetPath(ANum: Cardinal): TPath;
     function  GetPathCount: Integer;
-    function  GetText(ANum: Cardinal): TvText;
-    function  GetTextCount: Integer;
     function  GetEntity(ANum: Cardinal): TvEntity;
-    function  GetEntityCount: Integer;
+    function  GetEntitiesCount: Integer;
     { Data removing methods }
     procedure Clear;
-    procedure RemoveAllPaths;
-    procedure RemoveAllTexts;
     { Data writing methods }
-    procedure AddPath(APath: TPath);
-    procedure StartPath(AX, AY: Double);
+    procedure AddEntity(AEntity: TvEntity);
+    procedure AddPathCopyMem(APath: TPath);
+    procedure StartPath(AX, AY: Double); overload;
+    procedure StartPath(); overload;
+    procedure AddMoveToPath(AX, AY: Double);
     procedure AddLineToPath(AX, AY: Double); overload;
+    procedure AddLineToPath(AX, AY: Double; AColor: TFPColor); overload;
     procedure AddLineToPath(AX, AY, AZ: Double); overload;
+    procedure GetCurrenPathPenPos(var AX, AY: Double);
     procedure AddBezierToPath(AX1, AY1, AX2, AY2, AX3, AY3: Double); overload;
     procedure AddBezierToPath(AX1, AY1, AZ1, AX2, AY2, AZ2, AX3, AY3, AZ3: Double); overload;
+    procedure SetBrushColor(AColor: TFPColor);
+    procedure SetBrushStyle(AStyle: TFPBrushStyle);
+    procedure SetPenColor(AColor: TFPColor);
+    procedure SetPenStyle(AStyle: TFPPenStyle);
+    procedure SetPenWidth(AWidth: Integer);
     procedure EndPath();
     procedure AddText(AX, AY, AZ: Double; FontName: string; FontSize: integer; AText: utf8string); overload;
     procedure AddText(AX, AY, AZ: Double; AStr: utf8string); overload;
     procedure AddCircle(ACenterX, ACenterY, ACenterZ, ARadius: Double);
-    procedure AddCircularArc(ACenterX, ACenterY, ACenterZ, ARadius, AStartAngle, AEndAngle: Double);
+    procedure AddCircularArc(ACenterX, ACenterY, ACenterZ, ARadius, AStartAngle, AEndAngle: Double; AColor: TFPColor);
     procedure AddEllipse(CenterX, CenterY, CenterZ, MajorHalfAxis, MinorHalfAxis, Angle: Double);
+    // Dimensions
+    procedure AddAlignedDimension(BaseLeft, BaseRight, DimLeft, DimRight: T3DPoint);
     { properties }
     property PathCount: Integer read GetPathCount;
     property Paths[Index: Cardinal]: TPath read GetPath;
@@ -272,6 +350,7 @@
 procedure RegisterVectorialWriter(
   AWriterClass: TvVectorialWriterClass;
   AFormat: TvVectorialFormat);
+function Make2DPoint(AX, AY: Double): T3DPoint;
 
 implementation
 
@@ -362,6 +441,23 @@
   end;
 end;
 
+function Make2DPoint(AX, AY: Double): T3DPoint;
+begin
+  Result.X := AX;
+  Result.Y := AY;
+  Result.Z := 0;
+end;
+
+{ TvEntity }
+
+constructor TvEntity.Create;
+begin
+  Pen.Style := psSolid;
+  Pen.Color := colBlack;
+  Brush.Style := bsClear;
+  Brush.Color := colBlue;
+end;
+
 { TvEllipse }
 
 procedure TvEllipse.CalculateBoundingRectangle;
@@ -415,8 +511,6 @@
 begin
   inherited Create;
 
-  FPaths := TFPList.Create;
-  FTexts := TFPList.Create;
   FEntities := TFPList.Create;
   FTmpPath := TPath.Create;
 end;
@@ -428,40 +522,35 @@
 begin
   Clear;
 
-  FPaths.Free;
-  FTexts.Free;
   FEntities.Free;
 
   inherited Destroy;
 end;
 
-{@@
-  Clears the list of Vectors and releases their memory.
-}
-procedure TvVectorialDocument.RemoveAllPaths;
+procedure TvVectorialDocument.Assign(ASource: TvVectorialDocument);
+var
+  i: Integer;
 begin
-//  FPaths.ForEachCall(RemoveCallback, nil);
-  FPaths.Clear;
+  Clear;
+
+  for i := 0 to ASource.GetEntitiesCount - 1 do
+    Self.AddEntity(ASource.GetEntity(i));
 end;
 
-procedure TvVectorialDocument.RemoveAllTexts;
+procedure TvVectorialDocument.AssignTo(ADest: TvVectorialDocument);
 begin
-//  FTexts.ForEachCall(RemoveCallback, nil);
-  FTexts.Clear;
+  ADest.Assign(Self);
 end;
 
-procedure TvVectorialDocument.AddPath(APath: TPath);
+procedure TvVectorialDocument.AddPathCopyMem(APath: TPath);
 var
   lPath: TPath;
   Len: Integer;
 begin
   lPath := TPath.Create;
   lPath.Assign(APath);
-  FPaths.Add(Pointer(lPath));
+  AddEntity(lPath);
   //WriteLn(':>TvVectorialDocument.AddPath 1 Len = ', Len);
-  //WriteLn(':>TvVectorialDocument.AddPath 2');
-  //WriteLn(':>TvVectorialDocument.AddPath 3');
-  //WriteLn(':>TvVectorialDocument.AddPath 4');
 end;
 
 {@@
@@ -487,6 +576,23 @@
   FTmpPath.PointsEnd := segment;
 end;
 
+procedure TvVectorialDocument.StartPath();
+begin
+  ClearTmpPath();
+end;
+
+procedure TvVectorialDocument.AddMoveToPath(AX, AY: Double);
+var
+  segment: T2DSegment;
+begin
+  segment := T2DSegment.Create;
+  segment.SegmentType := stMoveTo;
+  segment.X := AX;
+  segment.Y := AY;
+
+  AppendSegmentToTmpPath(segment);
+end;
+
 {@@
   Adds one more point to the end of a Path being
   writing in multiple steps.
@@ -509,6 +615,19 @@
   AppendSegmentToTmpPath(segment);
 end;
 
+procedure TvVectorialDocument.AddLineToPath(AX, AY: Double; AColor: TFPColor);
+var
+  segment: T2DSegmentWithPen;
+begin
+  segment := T2DSegmentWithPen.Create;
+  segment.SegmentType := st2DLineWithPen;
+  segment.X := AX;
+  segment.Y := AY;
+  segment.Pen.Color := AColor;
+
+  AppendSegmentToTmpPath(segment);
+end;
+
 procedure TvVectorialDocument.AddLineToPath(AX, AY, AZ: Double);
 var
   segment: T3DSegment;
@@ -523,6 +642,18 @@
 end;
 
 {@@
+  Gets the current Pen Pos in the temporary path
+}
+procedure TvVectorialDocument.GetCurrenPathPenPos(var AX, AY: Double);
+begin
+  // Check if we are the first segment in the tmp path
+  if FTmpPath.PointsEnd = nil then raise Exception.Create('[TvVectorialDocument.GetCurrenPathPenPos] One cannot obtain the Pen Pos if there are no segments in the temporary path');
+
+  AX := T2DSegment(FTmpPath.PointsEnd).X;
+  AY := T2DSegment(FTmpPath.PointsEnd).Y;
+end;
+
+{@@
   Adds a bezier element to the path. It starts where the previous element ended
   and it goes throw the control points [AX1, AY1] and [AX2, AY2] and ends
   in [AX3, AY3].
@@ -564,6 +695,31 @@
   AppendSegmentToTmpPath(segment);
 end;
 
+procedure TvVectorialDocument.SetBrushColor(AColor: TFPColor);
+begin
+  FTmPPath.Brush.Color := AColor;
+end;
+
+procedure TvVectorialDocument.SetBrushStyle(AStyle: TFPBrushStyle);
+begin
+  FTmPPath.Brush.Style := AStyle;
+end;
+
+procedure TvVectorialDocument.SetPenColor(AColor: TFPColor);
+begin
+  FTmPPath.Pen.Color := AColor;
+end;
+
+procedure TvVectorialDocument.SetPenStyle(AStyle: TFPPenStyle);
+begin
+  FTmPPath.Pen.Style := AStyle;
+end;
+
+procedure TvVectorialDocument.SetPenWidth(AWidth: Integer);
+begin
+  FTmPPath.Pen.Width := AWidth;
+end;
+
 {@@
   Finishes writing a Path, which was created in multiple
   steps using StartPath and AddPointToPath,
@@ -577,7 +733,7 @@
 procedure TvVectorialDocument.EndPath();
 begin
   if FTmPPath.Len = 0 then Exit;
-  AddPath(FTmPPath);
+  AddPathCopyMem(FTmPPath);
   ClearTmpPath();
 end;
 
@@ -590,9 +746,9 @@
   lText.X := AX;
   lText.Y := AY;
   lText.Z := AZ;
-  lText.FontName := FontName;
-  lText.FontSize := FontSize;
-  FTexts.Add(lText);
+  lText.Font.Name := FontName;
+  lText.Font.Size := FontSize;
+  AddEntity(lText);
 end;
 
 procedure TvVectorialDocument.AddText(AX, AY, AZ: Double; AStr: utf8string);
@@ -609,11 +765,11 @@
   lCircle.CenterY := ACenterY;
   lCircle.CenterZ := ACenterZ;
   lCircle.Radius := ARadius;
-  FEntities.Add(lCircle);
+  AddEntity(lCircle);
 end;
 
 procedure TvVectorialDocument.AddCircularArc(ACenterX, ACenterY, ACenterZ,
-  ARadius, AStartAngle, AEndAngle: Double);
+  ARadius, AStartAngle, AEndAngle: Double; AColor: TFPColor);
 var
   lCircularArc: TvCircularArc;
 begin
@@ -624,7 +780,8 @@
   lCircularArc.Radius := ARadius;
   lCircularArc.StartAngle := AStartAngle;
   lCircularArc.EndAngle := AEndAngle;
-  FEntities.Add(lCircularArc);
+  lCircularArc.Pen.Color := AColor;
+  AddEntity(lCircularArc);
 end;
 
 procedure TvVectorialDocument.AddEllipse(CenterX, CenterY, CenterZ,
@@ -639,7 +796,28 @@
   lEllipse.MajorHalfAxis := MajorHalfAxis;
   lEllipse.MinorHalfAxis := MinorHalfAxis;
   lEllipse.Angle := Angle;
-  FEntities.Add(lEllipse);
+  AddEntity(lEllipse);
+end;
+
+{@@
+  Don't free the passed TvText because it will be added directly to the list
+}
+procedure TvVectorialDocument.AddEntity(AEntity: TvEntity);
+begin
+  FEntities.Add(Pointer(AEntity));
+end;
+
+procedure TvVectorialDocument.AddAlignedDimension(BaseLeft, BaseRight,
+  DimLeft, DimRight: T3DPoint);
+var
+  lDim: TvAlignedDimension;
+begin
+  lDim := TvAlignedDimension.Create;
+  lDim.BaseLeft := BaseLeft;
+  lDim.BaseRight := BaseRight;
+  lDim.DimensionLeft := DimLeft;
+  lDim.DimensionRight := DimRight;
+  AddEntity(lDim);
 end;
 
 {@@
@@ -655,12 +833,13 @@
   for i := 0 to Length(GvVectorialFormats) - 1 do
     if GvVectorialFormats[i].Format = AFormat then
     begin
-      Result := GvVectorialFormats[i].WriterClass.Create;
+      if GvVectorialFormats[i].WriterClass <> nil then
+        Result := GvVectorialFormats[i].WriterClass.Create;
 
       Break;
     end;
 
-  if Result = nil then raise Exception.Create('Unsuported vector graphics format.');
+  if Result = nil then raise Exception.Create('Unsupported vector graphics format.');
 end;
 
 {@@
@@ -676,12 +855,13 @@
   for i := 0 to Length(GvVectorialFormats) - 1 do
     if GvVectorialFormats[i].Format = AFormat then
     begin
-      Result := GvVectorialFormats[i].ReaderClass.Create;
+      if GvVectorialFormats[i].ReaderClass <> nil then
+        Result := GvVectorialFormats[i].ReaderClass.Create;
 
       Break;
     end;
 
-  if Result = nil then raise Exception.Create('Unsuported vector graphics format.');
+  if Result = nil then raise Exception.Create('Unsupported vector graphics format.');
 end;
 
 procedure TvVectorialDocument.ClearTmpPath();
@@ -700,14 +880,28 @@
   FTmpPath.Points := nil;
   FTmpPath.PointsEnd := nil;
   FTmpPath.Len := 0;
+  FTmpPath.Brush.Color := colBlue;
+  FTmpPath.Brush.Style := bsClear;
+  FTmpPath.Pen.Color := colBlack;
+  FTmpPath.Pen.Style := psSolid;
+  FTmpPath.Pen.Width := 1;
 end;
 
 procedure TvVectorialDocument.AppendSegmentToTmpPath(ASegment: TPathSegment);
 var
   L: Integer;
 begin
+  // Check if we are the first segment in the tmp path
   if FTmpPath.PointsEnd = nil then
-    Exception.Create('[TvVectorialDocument.AppendSegmentToTmpPath]' + Str_Error_Nil_Path);
+  begin
+    if FTmpPath.Len <> 0 then
+      Exception.Create('[TvVectorialDocument.AppendSegmentToTmpPath]' + Str_Error_Nil_Path);
+
+    FTmpPath.Points := ASegment;
+    FTmpPath.PointsEnd := ASegment;
+    FTmpPath.Len := 1;
+    Exit;
+  end;
 
   L := FTmpPath.Len;
   Inc(FTmpPath.Len);
@@ -736,6 +930,14 @@
   end;
 end;
 
+procedure TvVectorialDocument.WriteToFile(AFileName: string);
+var
+  lFormat: TvVectorialFormat;
+begin
+  lFormat := GetFormatFromExtension(ExtractFileExt(AFileName));
+  WriteToFile(AFileName, lFormat);
+end;
+
 {@@
   Writes the document to a stream
 }
@@ -787,6 +989,17 @@
 end;
 
 {@@
+  Reads the document from a file.  A variant that auto-detects the format from the extension.
+}
+procedure TvVectorialDocument.ReadFromFile(AFileName: string);
+var
+  lFormat: TvVectorialFormat;
+begin
+  lFormat := GetFormatFromExtension(ExtractFileExt(AFileName));
+  ReadFromFile(AFileName, lFormat);
+end;
+
+{@@
   Reads the document from a stream.
 
   Any current contents will be removed.
@@ -832,6 +1045,8 @@
   else if AnsiCompareText(lExt, STR_SVG_EXTENSION) = 0 then Result := vfSVG
   else if AnsiCompareText(lExt, STR_CORELDRAW_EXTENSION) = 0 then Result := vfCorelDrawCDR
   else if AnsiCompareText(lExt, STR_WINMETAFILE_EXTENSION) = 0 then Result := vfWindowsMetafileWMF
+  else if AnsiCompareText(lExt, STR_AUTOCAD_EXCHANGE_EXTENSION) = 0 then Result := vfDXF
+  else if AnsiCompareText(lExt, STR_ENCAPSULATEDPOSTSCRIPT_EXTENSION) = 0 then Result := vfEncapsulatedPostScript
   else
     raise Exception.Create('TvVectorialDocument.GetFormatFromExtension: The extension (' + lExt + ') doesn''t match any supported formats.');
 end;
@@ -842,31 +1057,32 @@
 end;
 
 function TvVectorialDocument.GetPath(ANum: Cardinal): TPath;
+var
+  i: Integer;
+  Index: Integer = - 1;
 begin
-  if ANum >= FPaths.Count then raise Exception.Create('TvVectorialDocument.GetPath: Path number out of bounds');
+  Result := nil;
 
-  if FPaths.Items[ANum] = nil then raise Exception.Create('TvVectorialDocument.GetPath: Invalid Path number');
+  if ANum >= FEntities.Count then raise Exception.Create('TvVectorialDocument.GetPath: Path number out of bounds');
 
-  Result := TPath(FPaths.Items[ANum]);
+  for i := 0 to FEntities.Count - 1 do
+  begin
+    if TvEntity(FEntities.Items[i]) is TPath then
+    begin
+      Inc(Index);
+      if Index = ANum then Result := TPath(FEntities.Items[i]);
+    end;
+  end;
 end;
 
 function TvVectorialDocument.GetPathCount: Integer;
+var
+  i: Integer;
 begin
-  Result := FPaths.Count;
-end;
-
-function TvVectorialDocument.GetText(ANum: Cardinal): TvText;
-begin
-  if ANum >= FTexts.Count then raise Exception.Create('TvVectorialDocument.GetText: Text number out of bounds');
+  Result := 0;
 
-  if FTexts.Items[ANum] = nil then raise Exception.Create('TvVectorialDocument.GetText: Invalid Text number');
-
-  Result := TvText(FTexts.Items[ANum]);
-end;
-
-function TvVectorialDocument.GetTextCount: Integer;
-begin
-  Result := FTexts.Count;
+  for i := 0 to FEntities.Count - 1 do
+    if TvEntity(FEntities.Items[i]) is TPath then Inc(Result);
 end;
 
 function TvVectorialDocument.GetEntity(ANum: Cardinal): TvEntity;
@@ -878,7 +1094,7 @@
   Result := TvEntity(FEntities.Items[ANum]);
 end;
 
-function TvVectorialDocument.GetEntityCount: Integer;
+function TvVectorialDocument.GetEntitiesCount: Integer;
 begin
   Result := FEntities.Count;
 end;
@@ -888,8 +1104,7 @@
 }
 procedure TvVectorialDocument.Clear;
 begin
-  RemoveAllPaths();
-  RemoveAllTexts();
+  FEntities.Clear();
 end;
 
 { TvCustomVectorialReader }
@@ -1000,17 +1215,14 @@
 
 { TPath }
 
-procedure TPath.Assign(APath: TPath);
+procedure TPath.Assign(ASource: TPath);
 begin
-  Len := APath.Len;
-  Points := APath.Points;
-  PointsEnd := APath.PointsEnd;
-  CurPoint := APath.CurPoint;
-end;
-
-function TPath.Count(): TPathSegment;
-begin
-
+  Len := ASource.Len;
+  Points := ASource.Points;
+  PointsEnd := ASource.PointsEnd;
+  CurPoint := ASource.CurPoint;
+  Pen := ASource.Pen;
+  Brush := ASource.Brush;
 end;
 
 procedure TPath.PrepareForSequentialReading;
