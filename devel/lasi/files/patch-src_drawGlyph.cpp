--- src/drawGlyph.cpp.orig	Wed Oct  4 16:21:41 2006
+++ src/drawGlyph.cpp	Wed Oct  4 16:23:29 2006
@@ -81,7 +81,7 @@
   return 0;
 }
 
-static int moveTo(FT_Vector* pftVec, void* data) {
+static int moveTo(const FT_Vector* pftVec, void* data) {
   StateOfDrawGlyph* const state = reinterpret_cast<StateOfDrawGlyph* const>(data);
   state->os() << (state->isNewPath() ? "newpath" : "closepath") << endl;
   state->setNewPathFalse();
@@ -89,19 +89,19 @@
   return 0;
 }
 
-static int lineTo(FT_Vector* pftVec, void* data) {
+static int lineTo(const FT_Vector* pftVec, void* data) {
   xTo(pftVec, data, "lineto");
   return 0;
 }
 
-static int cubicTo(FT_Vector* ctrlPt1, FT_Vector* ctrlPt2, FT_Vector* pEndPt, void* data) {
+static int cubicTo(const FT_Vector* ctrlPt1, const FT_Vector* ctrlPt2, const FT_Vector* pEndPt, void* data) {
   StateOfDrawGlyph* const state = reinterpret_cast<StateOfDrawGlyph* const>(data);
   state->os() << *ctrlPt1 << " " << *ctrlPt2 << " " << *pEndPt << " curveto" << endl;
   state->setStartPt(*pEndPt);
   return 0;
 }
 
-static int conicTo(FT_Vector* pCtrlPt, FT_Vector* pEndPt, void* data) {
+static int conicTo(const FT_Vector* pCtrlPt, const FT_Vector* pEndPt, void* data) {
   StateOfDrawGlyph* const state = reinterpret_cast<StateOfDrawGlyph* const>(data);
   FT_Vector ctrlPt1 = (state->startPt() + 2 * *pCtrlPt) / 3;
   FT_Vector ctrlPt2 = (*pEndPt + 2 * *pCtrlPt) / 3;
