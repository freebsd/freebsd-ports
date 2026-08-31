--- src/SWIG_files/wrapper/BOPAlgo.pyi.orig	2026-08-09 14:32:48 UTC
+++ src/SWIG_files/wrapper/BOPAlgo.pyi
@@ -157,7 +157,7 @@ class BOPAlgo_Tools:
 
 class BOPAlgo_Tools:
     @staticmethod
-    def ClassifyFaces(theFaces: TopTools_ListOfShape, theSolids: TopTools_ListOfShape, theRunParallel: bool, theContext: IntTools_Context, theInParts: TopTools_IndexedDataMapOfShapeListOfShape, theShapeBoxMap: Optional[TopTools_DataMapOfShapeBox] = NCollection_DataMap<TopoDS_Shape,Bnd_Box,TopTools_ShapeMapHasher>(), theSolidsIF: Optional[TopTools_DataMapOfShapeListOfShape] = NCollection_DataMap<TopoDS_Shape,NCollection_List<TopoDS_Shape>,TopTools_ShapeMapHasher>(), theRange: Optional[Message_ProgressRange] = Message_ProgressRange()) -> None: ...
+    def ClassifyFaces(theFaces: TopTools_ListOfShape, theSolids: TopTools_ListOfShape, theRunParallel: bool, theContext: IntTools_Context, theInParts: TopTools_IndexedDataMapOfShapeListOfShape, theShapeBoxMap: Optional[TopTools_DataMapOfShapeBox] = TopTools_DataMapOfShapeBox(), theSolidsIF: Optional[TopTools_DataMapOfShapeListOfShape] = TopTools_DataMapOfShapeListOfShape(), theRange: Optional[Message_ProgressRange] = Message_ProgressRange()) -> None: ...
     @staticmethod
     def ComputeToleranceOfCB(theCB: BOPDS_CommonBlock, theDS: BOPDS_PDS, theContext: IntTools_Context) -> False: ...
     @staticmethod
