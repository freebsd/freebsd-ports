--- packages/fpvectorial/src/avisocncgcodewriter.pas	2011/01/14 14:45:03	16765
+++ packages/fpvectorial/src/avisocncgcodewriter.pas	2011/03/08 14:28:26	17092
@@ -36,6 +36,10 @@
   i, j: Integer;
   Str: string;
   APath: TPath;
+  CurSegment: T2DSegment;
+  Cur3DSegment: T3DSegment;
+  Cur2DBezierSegment: T2DBezierSegment;
+  Cur3DBezierSegment: T3DBezierSegment;
 begin
   AStrings.Clear;
 
@@ -51,25 +55,39 @@
     // levanta a broca
     AStrings.Add('P01 // Sobe a cabeça de gravação');
     // vai para o ponto inicial
+    CurSegment := T2DSegment(APath.Points);
     AStrings.Add(Format('G01 X%f Y%f',
-      [APath.Points[0].X, APath.Points[0].Y]));
+      [CurSegment.X, CurSegment.Y]));
     AStrings.Add('P02 // Abaixa a cabeça de gravação');
 
     for j := 1 to APath.Len - 1 do
     begin
-      case APath.Points[j].SegmentType of
+      CurSegment := T2DSegment(CurSegment.Next);
+      case CurSegment.SegmentType of
       st2DLine: AStrings.Add(Format('G01 X%f Y%f',
-         [APath.Points[j].X, APath.Points[j].Y]));
-      st3DLine: AStrings.Add(Format('G01 X%f Y%f Z%f',
-         [APath.Points[j].X, APath.Points[j].Y, APath.Points[j].Z]));
-      st2DBezier: AStrings.Add(Format('B02 X%f Y%f X%f Y%f X%f Y%f',
-         [APath.Points[j].X2, APath.Points[j].Y2,
-          APath.Points[j].X3, APath.Points[j].Y3,
-          APath.Points[j].X, APath.Points[j].Y]));
-      st3DBezier: AStrings.Add(Format('B03 X%f Y%f Z%f X%f Y%f Z%f X%f Y%f Z%f',
-         [APath.Points[j].X2, APath.Points[j].Y2, APath.Points[j].Z2,
-          APath.Points[j].X3, APath.Points[j].Y3, APath.Points[j].Z3,
-          APath.Points[j].X, APath.Points[j].Y, APath.Points[j].Z]));
+         [CurSegment.X, CurSegment.Y]));
+      st3DLine:
+      begin
+        Cur3DSegment := T3DSegment(CurSegment);
+        AStrings.Add(Format('G01 X%f Y%f Z%f',
+         [Cur3DSegment.X, Cur3DSegment.Y, Cur3DSegment.Z]));
+      end;
+      st2DBezier:
+      begin
+        Cur2DBezierSegment := T2DBezierSegment(CurSegment);
+        AStrings.Add(Format('B02 X%f Y%f X%f Y%f X%f Y%f',
+         [Cur2DBezierSegment.X2, Cur2DBezierSegment.Y2,
+          Cur2DBezierSegment.X3, Cur2DBezierSegment.Y3,
+          Cur2DBezierSegment.X, Cur2DBezierSegment.Y]));
+      end;
+      st3DBezier:
+      begin
+        Cur3DBezierSegment := T3DBezierSegment(CurSegment);
+        AStrings.Add(Format('B03 X%f Y%f Z%f X%f Y%f Z%f X%f Y%f Z%f',
+         [Cur3DBezierSegment.X2, Cur3DBezierSegment.Y2, Cur3DBezierSegment.Z2,
+          Cur3DBezierSegment.X3, Cur3DBezierSegment.Y3, Cur3DBezierSegment.Z3,
+          Cur3DBezierSegment.X, Cur3DBezierSegment.Y, Cur3DBezierSegment.Z]));
+      end;
       end;
     end;
   end;
