--- src/framework/ui/graphicsapiprovider.cpp.orig	2025-01-16 06:06:20 UTC
+++ src/framework/ui/graphicsapiprovider.cpp
@@ -56,6 +56,13 @@ static const std::vector<GraphicsApiProvider::Api > AL
 };
 #endif
 
+#ifdef Q_OS_FREEBSD
+static const std::vector<GraphicsApiProvider::Api > ALLOWED_APIS = {
+    GraphicsApiProvider::OpenGL,
+    GraphicsApiProvider::Software
+};
+#endif
+
 static const std::vector<std::string> BAD_MESSAGES = {
     "Failed to build graphics pipeline state",
     "Failed to create RHI",
