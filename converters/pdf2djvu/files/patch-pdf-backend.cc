--- pdf-backend.cc.orig	2019-06-10 17:06:44 UTC
+++ pdf-backend.cc
@@ -48,7 +48,7 @@
  * ======================
  */
 
-static void poppler_error_handler(void *data, ErrorCategory category, pdf::Offset pos, const char *message)
+static void poppler_error_handler_new(ErrorCategory category, pdf::Offset pos, const char *message)
 {
   std::string format;
   const char *category_name = _("PDF error");
@@ -94,6 +94,11 @@ static void poppler_error_handler(void *data, ErrorCat
   error_log << std::endl;
 }
 
+static void poppler_error_handler(void *data, ErrorCategory category, pdf::Offset pos, const char *message)
+{
+	  poppler_error_handler_new(category, pos, message);
+}
+
 #if POPPLER_VERSION < 7000
 static void poppler_error_handler(void *data, ErrorCategory category, pdf::Offset pos, char *message)
 {
@@ -101,10 +106,26 @@ static void poppler_error_handler(void *data, ErrorCat
 }
 #endif
 
+// for POPPLER_VERSION >= 8500:
+template <typename T1, typename T2> static auto set_error_callback(T1 callback1, T2 callback2) -> decltype(setErrorCallback(callback2))
+{
+	  setErrorCallback(callback2);
+}
+
+// for POPPLER_VERSION < 8500:
+template <typename T1, typename T2> static auto set_error_callback(T1 callback1, T2 callback2) -> decltype(setErrorCallback(callback1, nullptr))
+{
+	  setErrorCallback(callback1, nullptr);
+}
+
 pdf::Environment::Environment()
 {
-  globalParams = new GlobalParams();
+  globalParams = std::unique_ptr<GlobalParams>(new GlobalParams);
+#if POPPLER_VERSION >= 7000
+    set_error_callback(poppler_error_handler, poppler_error_handler_new);
+#else
   setErrorCallback(poppler_error_handler, nullptr);
+#endif
 }
 
 void pdf::Environment::set_antialias(bool value)
@@ -499,12 +520,11 @@ bool pdf::get_glyph(splash::Splash *splash, splash::Fo
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
