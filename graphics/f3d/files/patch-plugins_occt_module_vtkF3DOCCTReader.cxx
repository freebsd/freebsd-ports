--- plugins/occt/module/vtkF3DOCCTReader.cxx.orig	2024-01-21 15:29:01 UTC
+++ plugins/occt/module/vtkF3DOCCTReader.cxx
@@ -31,14 +31,17 @@
 #if F3D_PLUGIN_OCCT_XCAF
 #include <IGESCAFControl_Reader.hxx>
 #include <STEPCAFControl_Reader.hxx>
+#include <Standard_Version.hxx>
 #include <TDF_ChildIterator.hxx>
 #include <TDataStd_Name.hxx>
 #include <TDocStd_Document.hxx>
 #include <XCAFApp_Application.hxx>
-#include <XCAFDoc_ColorTool.hxx>
 #include <XCAFDoc_DocumentTool.hxx>
 #include <XCAFDoc_Location.hxx>
 #include <XCAFDoc_ShapeTool.hxx>
+#include <XCAFPrs.hxx>
+#include <XCAFPrs_IndexedDataMapOfShapeStyle.hxx>
+#include <XCAFPrs_Style.hxx>
 #endif
 
 #if defined(__GNUC__)
@@ -71,6 +74,10 @@ class vtkF3DOCCTReader::vtkInternals
 
 class vtkF3DOCCTReader::vtkInternals
 {
+#if F3D_PLUGIN_OCCT_XCAF
+  using StyleMap = XCAFPrs_IndexedDataMapOfShapeStyle;
+#endif
+
 public:
   //----------------------------------------------------------------------------
   explicit vtkInternals(vtkF3DOCCTReader* parent)
@@ -79,7 +86,11 @@ class vtkF3DOCCTReader::vtkInternals
   }
 
   //----------------------------------------------------------------------------
+#if F3D_PLUGIN_OCCT_XCAF
+  vtkSmartPointer<vtkPolyData> CreateShape(const TopoDS_Shape& shape, const TDF_Label& label)
+#else
   vtkSmartPointer<vtkPolyData> CreateShape(const TopoDS_Shape& shape)
+#endif
   {
     vtkNew<vtkPoints> points;
     vtkNew<vtkFloatArray> normals;
@@ -88,32 +99,49 @@ class vtkF3DOCCTReader::vtkInternals
     vtkNew<vtkFloatArray> uvs;
     uvs->SetNumberOfComponents(2);
     uvs->SetName("UV");
+#if F3D_PLUGIN_OCCT_XCAF
     vtkNew<vtkUnsignedCharArray> colors;
     colors->SetNumberOfComponents(3);
     colors->SetName("Colors");
+#endif
     vtkNew<vtkCellArray> trianglesCells;
     vtkNew<vtkCellArray> linesCells;
 
     Standard_Integer shift = 0;
 
+#if F3D_PLUGIN_OCCT_XCAF
+    const StyleMap inheritedStyles = this->CollectInheritedStyles(label, shape);
+#endif
+
+    /* Mesh the whole shape. This only affect faces, edges have to be handled separately. */
+    BRepMesh_IncrementalMesh(shape, this->Parent->GetLinearDeflection(),
+      this->Parent->GetRelativeDeflection(), this->Parent->GetAngularDeflection(), Standard_True);
+
     if (this->Parent->GetReadWire())
     {
-      // Add all edges to polydata
-      for (TopExp_Explorer exEdge(shape, TopAbs_EDGE); exEdge.More(); exEdge.Next())
+      std::vector<TopoDS_Edge> edges;
       {
-        TopoDS_Edge edge = TopoDS::Edge(exEdge.Current());
+        /* add all edges to a compound to remesh them all at once */
+        TopoDS_Builder builder;
+        TopoDS_Compound compound;
+        builder.MakeCompound(compound);
+        for (TopExp_Explorer exEdge(shape, TopAbs_EDGE); exEdge.More(); exEdge.Next())
+        {
+          const TopoDS_Edge edge = TopoDS::Edge(exEdge.Current());
+          builder.Add(compound, edge);
+          edges.push_back(edge);
+        }
+        BRepMesh_IncrementalMesh(compound, this->Parent->GetLinearDeflection(),
+          this->Parent->GetRelativeDeflection(), this->Parent->GetAngularDeflection(),
+          Standard_True);
+      }
 
+      // Add all edges to polydata
+      for (const TopoDS_Edge& edge : edges)
+      {
         TopLoc_Location location;
         const auto& poly = BRep_Tool::Polygon3D(edge, location);
 
-        if (poly.IsNull() || poly->Nodes().Length() <= 0)
-        {
-          // meshing
-          BRepMesh_IncrementalMesh(edge, this->Parent->GetLinearDeflection(),
-            this->Parent->GetRelativeDeflection(), this->Parent->GetAngularDeflection(),
-            Standard_True);
-        }
-
         if (poly.IsNull())
         {
           continue;
@@ -134,23 +162,29 @@ class vtkF3DOCCTReader::vtkInternals
           uvs->InsertNextTypedTuple(fn);
         }
 
-        std::vector<vtkIdType> polyline(nbV - 1);
+        std::vector<vtkIdType> polyline(nbV);
         std::iota(polyline.begin(), polyline.end(), shift);
         linesCells->InsertNextCell(polyline.size(), polyline.data());
 
 #if F3D_PLUGIN_OCCT_XCAF
-        if (this->ColorTool)
+        std::array<unsigned char, 3> rgb = { 0, 0, 0 };
+        try
         {
-          std::array<unsigned char, 3> rgb = { 0, 0, 0 };
-          Quantity_Color aColor;
-          if (this->ColorTool->GetColor(edge, XCAFDoc_ColorCurv, aColor))
+          const auto& style = inheritedStyles.FindFromKey(edge);
+          if (style.IsSetColorCurv())
           {
-            rgb[0] = static_cast<unsigned char>(255.0 * aColor.Red());
-            rgb[1] = static_cast<unsigned char>(255.0 * aColor.Green());
-            rgb[2] = static_cast<unsigned char>(255.0 * aColor.Blue());
+            Quantity_Color color = style.GetColorCurv();
+            rgb[0] = static_cast<unsigned char>(255.0 * color.Red());
+            rgb[1] = static_cast<unsigned char>(255.0 * color.Green());
+            rgb[2] = static_cast<unsigned char>(255.0 * color.Blue());
           }
-          colors->InsertNextTypedTuple(rgb.data());
         }
+        catch (Standard_NoSuchObject&)
+        {
+          /* edge has no style, safe to ignore */
+        }
+
+        colors->InsertNextTypedTuple(rgb.data());
 #endif
 
         shift += nbV;
@@ -165,14 +199,6 @@ class vtkF3DOCCTReader::vtkInternals
       TopLoc_Location location;
       const auto& poly = BRep_Tool::Triangulation(face, location);
 
-      if (poly.IsNull() || poly->NbTriangles() <= 0)
-      {
-        // meshing
-        BRepMesh_IncrementalMesh(face, this->Parent->GetLinearDeflection(),
-          this->Parent->GetRelativeDeflection(), this->Parent->GetAngularDeflection(),
-          Standard_True);
-      }
-
       if (poly.IsNull())
       {
         continue;
@@ -243,23 +269,32 @@ class vtkF3DOCCTReader::vtkInternals
           std::swap(cell[0], cell[2]);
         }
         trianglesCells->InsertNextCell(3, cell);
+      }
 
 #if F3D_PLUGIN_OCCT_XCAF
-        if (this->ColorTool)
+      std::array<unsigned char, 3> rgb = { 255, 255, 255 };
+      try
+      {
+        const auto& style = inheritedStyles.FindFromKey(face);
+        if (style.IsSetColorSurf())
         {
-          std::array<unsigned char, 3> rgb = { 255, 255, 255 };
-          Quantity_Color aColor;
-          if (this->ColorTool->GetColor(face, XCAFDoc_ColorSurf, aColor))
-          {
-            rgb[0] = static_cast<unsigned char>(255.0 * aColor.Red());
-            rgb[1] = static_cast<unsigned char>(255.0 * aColor.Green());
-            rgb[2] = static_cast<unsigned char>(255.0 * aColor.Blue());
-          }
-          colors->InsertNextTypedTuple(rgb.data());
+          Quantity_Color color = style.GetColorSurf();
+          rgb[0] = static_cast<unsigned char>(255.0 * color.Red());
+          rgb[1] = static_cast<unsigned char>(255.0 * color.Green());
+          rgb[2] = static_cast<unsigned char>(255.0 * color.Blue());
         }
-#endif
       }
+      catch (Standard_NoSuchObject&)
+      {
+        /* face has no style, safe to ignore */
+      }
 
+      for (int i = 1; i <= nbT; i++)
+      {
+        colors->InsertNextTypedTuple(rgb.data());
+      }
+#endif
+
       shift += nbV;
     }
 
@@ -271,11 +306,7 @@ class vtkF3DOCCTReader::vtkInternals
     polydata->SetLines(linesCells);
 
 #if F3D_PLUGIN_OCCT_XCAF
-    /* colors may be left empty if this->ColorTool has not been initialized */
-    if (colors->GetSize() > 0)
-    {
-      polydata->GetCellData()->SetScalars(colors);
-    }
+    polydata->GetCellData()->SetScalars(colors);
 #endif
 
     polydata->Squeeze();
@@ -283,7 +314,99 @@ class vtkF3DOCCTReader::vtkInternals
   }
 
 #if F3D_PLUGIN_OCCT_XCAF
+  StyleMap CollectInheritedStyles(const TDF_Label& rootLabel, const TopoDS_Shape& rootShape)
+  {
+    StyleMap inheritedStyles;
+
+    if (rootLabel.IsNull())
+    {
+      return inheritedStyles;
+    }
+
+    /* collect styled shapes from the document */
+    StyleMap collectedStyles;
+    XCAFPrs::CollectStyleSettings(rootLabel, TopLoc_Location(), collectedStyles);
+
+    /* iterate styled shapes and collect sorted by ascending shape type depth */
+    const auto cmp = [](const TopoDS_Shape& a, const TopoDS_Shape& b)
+    { return a.ShapeType() > b.ShapeType(); };
+    std::multimap<TopoDS_Shape, XCAFPrs_Style, decltype(cmp)> styledShapes(cmp);
+
+    const TopAbs_ShapeEnum leafType = this->Parent->GetReadWire() ? TopAbs_EDGE : TopAbs_FACE;
+    for (StyleMap::Iterator iter(collectedStyles); iter.More(); iter.Next())
+    {
+      const TopoDS_Shape& shape = iter.Key();
+      if (shape.ShapeType() <= leafType)
+      {
+        styledShapes.insert({ shape, iter.Value() });
+      }
+    }
+
+    /* pass down each parent style props to descendent edge/face leaves */
+    const auto passDownToLeaves = [&](TopAbs_ShapeEnum type)
+    {
+      for (const auto& styledShape : styledShapes)
+      {
+        for (TopExp_Explorer iter(styledShape.first, type); iter.More(); iter.Next())
+        {
+          try
+          {
+            this->PassDownStyleProps(
+              styledShape.second, inheritedStyles.ChangeFromKey(iter.Current()));
+          }
+          catch (Standard_NoSuchObject&)
+          {
+            inheritedStyles.Add(iter.Current(), styledShape.second);
+          }
+        }
+      }
+    };
+
+    passDownToLeaves(TopAbs_FACE);
+
+    if (this->Parent->GetReadWire())
+    {
+      passDownToLeaves(TopAbs_EDGE);
+    }
+
+    /* pass down default style (if any) to all leaves */
+    try
+    {
+      const XCAFPrs_Style& defaultStyle = collectedStyles.FindFromKey(rootShape);
+      for (StyleMap::Iterator iter(inheritedStyles); iter.More(); iter.Next())
+      {
+        XCAFPrs_Style style = iter.Value();
+        this->PassDownStyleProps(defaultStyle, style);
+      }
+    }
+    catch (Standard_NoSuchObject&)
+    {
+      /* root shape has no style, safe to ignore */
+    }
+
+    return inheritedStyles;
+  }
+
   //----------------------------------------------------------------------------
+  void PassDownStyleProps(const XCAFPrs_Style& parent, XCAFPrs_Style& child)
+  {
+    if (!child.IsSetColorCurv() && parent.IsSetColorCurv())
+    {
+      child.SetColorCurv(parent.GetColorCurv());
+    }
+
+    if (!child.IsSetColorSurf() && parent.IsSetColorSurf())
+    {
+      child.SetColorSurf(parent.GetColorSurfRGBA());
+    }
+
+    if (child.Material().IsNull() && !parent.Material().IsNull())
+    {
+      child.SetMaterial(parent.Material());
+    }
+  };
+
+  //----------------------------------------------------------------------------
   void AddLabel(const TDF_Label& label, vtkMatrix4x4* position, vtkMultiBlockDataSet* mb)
   {
     if (this->ShapeTool->IsSimpleShape(label) && this->ShapeTool->IsTopLevel(label))
@@ -365,7 +488,11 @@ class vtkF3DOCCTReader::vtkInternals
   int GetHash(const TDF_Label& label)
   {
     TopoDS_Shape aShape;
+#if OCC_VERSION_HEX < 0x070800
     return this->ShapeTool->GetShape(label, aShape) ? aShape.HashCode(INT_MAX) : 0;
+#else
+    return this->ShapeTool->GetShape(label, aShape) ? std::hash<TopoDS_Shape>{}(aShape) : 0;
+#endif
   }
 
   //----------------------------------------------------------------------------
@@ -401,7 +528,6 @@ class vtkF3DOCCTReader::vtkInternals
 
   std::unordered_map<int, vtkSmartPointer<vtkPolyData> > ShapeMap;
   Handle(XCAFDoc_ShapeTool) ShapeTool;
-  Handle(XCAFDoc_ColorTool) ColorTool;
 #endif
 
   vtkF3DOCCTReader* Parent;
@@ -424,7 +550,10 @@ class ProgressIndicator : public Message_ProgressIndic
 class ProgressIndicator : public Message_ProgressIndicator
 {
 public:
-  explicit ProgressIndicator(vtkF3DOCCTReader* reader) { this->Reader = reader; }
+  explicit ProgressIndicator(vtkF3DOCCTReader* reader)
+  {
+    this->Reader = reader;
+  }
 
 protected:
   void Show(const Message_ProgressScope&, const Standard_Boolean) override
@@ -493,7 +622,12 @@ int vtkF3DOCCTReader::RequestData(
     if (success)
     {
       output->SetNumberOfBlocks(1);
+#if F3D_PLUGIN_OCCT_XCAF
+      const vtkSmartPointer<vtkPolyData> polydata =
+        this->Internals->CreateShape(shape, TDF_Label());
+#else
       const vtkSmartPointer<vtkPolyData> polydata = this->Internals->CreateShape(shape);
+#endif
       if (polydata && polydata->GetNumberOfCells() > 0)
       {
         output->SetBlock(1, polydata);
@@ -522,7 +656,6 @@ int vtkF3DOCCTReader::RequestData(
   }
 
   this->Internals->ShapeTool = XCAFDoc_DocumentTool::ShapeTool(doc->Main());
-  this->Internals->ColorTool = XCAFDoc_DocumentTool::ColorTool(doc->Main());
 
   TDF_LabelSequence topLevelShapes;
 
@@ -537,9 +670,9 @@ int vtkF3DOCCTReader::RequestData(
     this->Internals->ShapeTool->GetShape(label, shape);
 
     this->Internals->ShapeMap[this->Internals->GetHash(label)] =
-      this->Internals->CreateShape(shape);
+      this->Internals->CreateShape(shape, label);
 
-    double progress = 0.5 + static_cast<double>(iLabel) / topLevelShapes.Length();
+    double progress = 0.5 + (static_cast<double>(iLabel) / topLevelShapes.Length()) / 2;
     this->InvokeEvent(vtkCommand::ProgressEvent, &progress);
   }
 
