--- pdf-backend.cc.orig	2019-06-10 17:06:44 UTC
+++ pdf-backend.cc
@@ -103,7 +103,7 @@ static void poppler_error_handler(void *data, ErrorCat
 
 pdf::Environment::Environment()
 {
-  globalParams = new GlobalParams();
+  globalParams = std::unique_ptr<GlobalParams>(new GlobalParams);
   setErrorCallback(poppler_error_handler, nullptr);
 }
 
@@ -499,12 +499,11 @@ bool pdf::get_glyph(splash::Splash *splash, splash::Fo
 void pdf::Renderer::convert_path(pdf::gfx::State *state, splash::Path &splash_path)
 {
   /* Source was copied from <poppler/SplashOutputDev.c>. */
-  pdf::gfx::Subpath *subpath;
-  pdf::gfx::Path *path = state->getPath();
+  auto path = state->getPath();
   int n_subpaths = path->getNumSubpaths();
   for (int i = 0; i < n_subpaths; i++)
   {
-    subpath = path->getSubpath(i);
+    auto subpath = path->getSubpath(i);
     if (subpath->getNumPoints() > 0)
     {
       double x1, y1, x2, y2, x3, y3;
