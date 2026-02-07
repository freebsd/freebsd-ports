--- COLLADAStreamWriter/src/COLLADASWLibraryAnimations.cpp.orig	2017-05-10 01:36:49 UTC
+++ COLLADAStreamWriter/src/COLLADASWLibraryAnimations.cpp
@@ -62,7 +62,7 @@ namespace COLLADASW
 
     //---------------------------------------------------------------
     LibraryAnimations::LibraryAnimations ( COLLADASW::StreamWriter * streamWriter )
-            : Library ( streamWriter, CSWC::CSW_ELEMENT_LIBRARY_ANIMATIONS ), mOpenAnimations ( NULL )
+            : Library ( streamWriter, CSWC::CSW_ELEMENT_LIBRARY_ANIMATIONS )
     {}
 
     //---------------------------------------------------------------
