--- dpf/dgl/src/Window.cpp.orig	2018-04-11 22:29:29 UTC
+++ dpf/dgl/src/Window.cpp
@@ -1148,10 +1148,11 @@ bool Window::openFileBrowser(const FileB
     // TODO: cross-platform
 
     String startDir(options.startDir);
+    static char buf[1024];
 
     if (startDir.isEmpty())
     {
-        if (char* const dir_name = get_current_dir_name())
+        if (char* const dir_name = getwd(buf))
         {
             startDir = dir_name;
             std::free(dir_name);
