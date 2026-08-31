--- src/SWIG_files/wrapper/BRepAlgoAPI.pyi.orig	2026-08-09 14:32:48 UTC
+++ src/SWIG_files/wrapper/BRepAlgoAPI.pyi
@@ -138,7 +138,7 @@ class BRepAlgoAPI_Section(BRepAlgoAPI_BooleanOperation
     def Init2(self, Sf: Geom_Surface) -> None: ...
 
 #classnotwrapped
-class BRepAlgoAPI_BuilderAlgo: ...
+class BRepAlgoAPI_BuilderAlgo(BRepAlgoAPI_Algo): ...
 
 # harray1 classes
 # harray2 classes
