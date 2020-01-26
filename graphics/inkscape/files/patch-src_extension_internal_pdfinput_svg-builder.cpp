--- src/extension/internal/pdfinput/svg-builder.cpp.orig	2020-01-25 21:47:43 UTC
+++ src/extension/internal/pdfinput/svg-builder.cpp
@@ -264,10 +264,10 @@ static void svgSetTransform(Inkscape::XML::Node *node,
 /**
  * \brief Generates a SVG path string from poppler's data structure
  */
-static gchar *svgInterpretPath(GfxPath *path) {
+static gchar *svgInterpretPath(const GfxPath *path) {
     Inkscape::SVG::PathString pathString;
     for (int i = 0 ; i < path->getNumSubpaths() ; ++i ) {
-        GfxSubpath *subpath = path->getSubpath(i);
+        const GfxSubpath *subpath = path->getSubpath(i);
         if (subpath->getNumPoints() > 0) {
             pathString.moveTo(subpath->getX(0), subpath->getY(0));
             int j = 1;
