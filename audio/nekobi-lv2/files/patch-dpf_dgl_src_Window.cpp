--- dpf/dgl/src/Window.cpp.orig	2018-09-25 22:56:57 UTC
+++ dpf/dgl/src/Window.cpp
@@ -18,6 +18,7 @@
 //#define PUGL_GRAB_FOCUS 1
 
 #include "../Base.hpp"
+#include <unistd.h>
 
 #undef PUGL_HAVE_CAIRO
 #undef PUGL_HAVE_GL
@@ -1164,7 +1165,8 @@ bool Window::openFileBrowser(const FileB
 
     if (startDir.isEmpty())
     {
-        if (char* const dir_name = get_current_dir_name())
+        char buf[MAXPATHLEN];
+        if (char* const dir_name = getwd(buf))
         {
             startDir = dir_name;
             std::free(dir_name);
