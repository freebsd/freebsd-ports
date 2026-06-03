Update OpenGL and VTK headers for VTK 9 compatibility.

VTK 9 removed several deprecated headers and changed OpenGL handling:
- Removed vtk_glew.h and vtkOpenGL.h (no longer needed)
- Added vtkOpenGLState.h and vtk_glad.h for modern OpenGL
- Replaced vtkgl::BlendEquationEXT with standard glBlendEquation
  (OpenGL 3.2+ has blend equations built-in, no extensions needed)

--- vv/vvBlendImageActor.cxx.orig	2025-04-17 12:54:38 UTC
+++ vv/vvBlendImageActor.cxx
@@ -3,7 +3,7 @@ - University of LYON              http://www.universit
 
 Authors belong to:
 - University of LYON              http://www.universite-lyon.fr/
-- Léon Bérard cancer center       http://www.centreleonberard.fr
+- Lï¿½on Bï¿½rard cancer center       http://www.centreleonberard.fr
 - CREATIS CNRS laboratory         http://www.creatis.insa-lyon.fr
 
 This software is distributed WITHOUT ANY WARRANTY; without even
@@ -17,11 +17,11 @@ - CeCILL-B   http://www.cecill.info/licences/Licence_C
 ===========================================================================**/
 
 #include "vvBlendImageActor.h"
-#include <vtk_glew.h>
 #include <vtkOpenGLRenderWindow.h>
 #include <vtkOpenGLRenderer.h>
-#include <vtkOpenGL.h>
 #include <vtkObjectFactory.h>
+#include <vtkOpenGLState.h>
+#include <vtk_glad.h>
 
 vtkStandardNewMacro(vvBlendImageActor);
 
@@ -45,19 +45,14 @@ void vvBlendImageActor::Render(vtkRenderer *ren)
   VTK_IMAGE_ACTOR::Render(ren);
 
 #else
-  vtkOpenGLExtensionManager *extensions = renwin->GetExtensionManager();
-  if (extensions->ExtensionSupported("GL_EXT_blend_minmax")) {
-    extensions->LoadExtension("GL_EXT_blend_minmax");
-    vtkgl::BlendEquationEXT( vtkgl::MAX );
-  }
+  // VTK 9 uses OpenGL 3.2+ which has blend equations built-in
+  glBlendEquation(GL_MAX);
 
   //Call normal render
   VTK_IMAGE_ACTOR::Render(ren);
 
   //Move back blending to weighted sum
-  if (vtkgl::BlendEquationEXT!=0) {
-    vtkgl::BlendEquationEXT( vtkgl::FUNC_ADD );
-  }
+  glBlendEquation(GL_FUNC_ADD);
 #endif
 }
 
