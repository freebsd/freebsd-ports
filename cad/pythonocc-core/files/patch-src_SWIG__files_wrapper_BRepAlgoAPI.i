--- src/SWIG_files/wrapper/BRepAlgoAPI.i.orig	2026-08-06 17:32:08 UTC
+++ src/SWIG_files/wrapper/BRepAlgoAPI.i
@@ -148,10 +148,10 @@ -----------
 
 Description
 -----------
-Constructor for checking single shape. //! 
-Input parameter: theS - the shape to check; 
-Input parameter: bTestSE - flag which specifies whether to check the shape  on small edges or not; by default it is set to True; 
-Input parameter: bTestSI - flag which specifies whether to check the shape  on self-interference or not; by default it is set to True; 
+Constructor for checking single shape. //!
+Input parameter: theS - the shape to check;
+Input parameter: bTestSE - flag which specifies whether to check the shape  on small edges or not; by default it is set to True;
+Input parameter: bTestSI - flag which specifies whether to check the shape  on self-interference or not; by default it is set to True;
 Input parameter: theRange - parameter to use progress indicator.
 ") BRepAlgoAPI_Check;
 		 BRepAlgoAPI_Check(const TopoDS_Shape & theS, const bool bTestSE = true, const bool bTestSI = true, const Message_ProgressRange & theRange = Message_ProgressRange());
@@ -175,12 +175,12 @@ -----------
 
 Description
 -----------
-Constructor for checking the couple of shapes. Additionally to the validity checks of each given shape, the types of the given shapes will be checked on validity for Boolean operation of given type. //! 
-Input parameter: theS1 - the first shape to check; 
-Input parameter: theS2 - the second shape to check; 
-Input parameter: theOp - the type of Boolean Operation for which the validity of given shapes should be checked. 
-Input parameter: bTestSE - flag which specifies whether to check the shape  on small edges or not; by default it is set to True; 
-Input parameter: bTestSI - flag which specifies whether to check the shape  on self-interference or not; by default it is set to True; 
+Constructor for checking the couple of shapes. Additionally to the validity checks of each given shape, the types of the given shapes will be checked on validity for Boolean operation of given type. //!
+Input parameter: theS1 - the first shape to check;
+Input parameter: theS2 - the second shape to check;
+Input parameter: theOp - the type of Boolean Operation for which the validity of given shapes should be checked.
+Input parameter: bTestSE - flag which specifies whether to check the shape  on small edges or not; by default it is set to True;
+Input parameter: bTestSI - flag which specifies whether to check the shape  on self-interference or not; by default it is set to True;
 Input parameter: theRange - parameter to use progress indicator.
 ") BRepAlgoAPI_Check;
 		 BRepAlgoAPI_Check(const TopoDS_Shape & theS1, const TopoDS_Shape & theS2, const BOPAlgo_Operation theOp = BOPAlgo_UNKNOWN, const bool bTestSE = true, const bool bTestSI = true, const Message_ProgressRange & theRange = Message_ProgressRange());
@@ -245,9 +245,9 @@ -----------
 
 Description
 -----------
-Initializes the algorithm with single shape. //! 
-Input parameter: theS - the shape to check; 
-Input parameter: bTestSE - flag which specifies whether to check the shape  on small edges or not; by default it is set to True; 
+Initializes the algorithm with single shape. //!
+Input parameter: theS - the shape to check;
+Input parameter: bTestSE - flag which specifies whether to check the shape  on small edges or not; by default it is set to True;
 Input parameter: bTestSI - flag which specifies whether to check the shape  on self-interference or not; by default it is set to True;.
 ") SetData;
 		void SetData(const TopoDS_Shape & theS, const bool bTestSE = true, const bool bTestSI = true);
@@ -270,11 +270,11 @@ -----------
 
 Description
 -----------
-Initializes the algorithm with couple of shapes. Additionally to the validity checks of each given shape, the types of the given shapes will be checked on validity for Boolean operation of given type. //! 
-Input parameter: theS1 - the first shape to check; 
-Input parameter: theS2 - the second shape to check; 
-Input parameter: theOp - the type of Boolean Operation for which the validity of given shapes should be checked. 
-Input parameter: bTestSE - flag which specifies whether to check the shape  on small edges or not; by default it is set to True; 
+Initializes the algorithm with couple of shapes. Additionally to the validity checks of each given shape, the types of the given shapes will be checked on validity for Boolean operation of given type. //!
+Input parameter: theS1 - the first shape to check;
+Input parameter: theS2 - the second shape to check;
+Input parameter: theOp - the type of Boolean Operation for which the validity of given shapes should be checked.
+Input parameter: bTestSE - flag which specifies whether to check the shape  on small edges or not; by default it is set to True;
 Input parameter: bTestSI - flag which specifies whether to check the shape  on self-interference or not; by default it is set to True;.
 ") SetData;
 		void SetData(const TopoDS_Shape & theS1, const TopoDS_Shape & theS2, const BOPAlgo_Operation theOp = BOPAlgo_UNKNOWN, const bool bTestSE = true, const bool bTestSI = true);
@@ -320,6 +320,22 @@ Returns a shape built by the shape construction algori
 /********************************
 * class BRepAlgoAPI_BuilderAlgo *
 ********************************/
+// occt-800: BRepAlgoAPI_BuilderAlgo gained deleted copy/move members, so the
+// generator dropped it into the excluded-classes list. That severed the
+// inheritance chain (BooleanOperation/Splitter -> BuilderAlgo -> Algo), hiding
+// the inherited Shape() from every boolean operation. Re-wrap it (empty body
+// is enough) so Shape() is exposed again.
+%nodefaultctor BRepAlgoAPI_BuilderAlgo;
+class BRepAlgoAPI_BuilderAlgo : public BRepAlgoAPI_Algo {
+	public:
+};
+
+%extend BRepAlgoAPI_BuilderAlgo {
+	%pythoncode {
+	__repr__ = _dumps_object
+	}
+};
+
 /********************************
 * class BRepAlgoAPI_Defeaturing *
 ********************************/
@@ -352,7 +368,7 @@ -----------
 
 Description
 -----------
-Adds the features to remove from the input shape. 
+Adds the features to remove from the input shape.
 Input parameter: theFace The shape to extract the faces for removal.
 ") AddFaceToRemove;
 		void AddFaceToRemove(const TopoDS_Shape & theFace);
@@ -371,7 +387,7 @@ -----------
 
 Description
 -----------
-Adds the faces to remove from the input shape. 
+Adds the faces to remove from the input shape.
 Input parameter: theFaces The list of shapes to extract the faces for removal.
 ") AddFacesToRemove;
 		void AddFacesToRemove(const TopTools_ListOfShape & theFaces);
@@ -553,7 +569,7 @@ -----------
 
 Description
 -----------
-Sets the shape for processing. 
+Sets the shape for processing.
 Input parameter: theShape The shape to remove the features from.  It should either be the SOLID, COMPSOLID or COMPOUND of Solids.
 ") SetShape;
 		void SetShape(const TopoDS_Shape & theShape);
@@ -1475,10 +1491,6 @@ initialize the tool <Sf> - tool Obsolete.
 
 /* python proxy for excluded classes */
 %pythoncode {
-@classnotwrapped
-class BRepAlgoAPI_BuilderAlgo:
-	pass
-
 }
 /* end python proxy for excluded classes */
 /* harray1 classes */
