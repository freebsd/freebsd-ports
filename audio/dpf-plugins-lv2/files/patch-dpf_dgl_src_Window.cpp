--- dpf/dgl/src/Window.cpp.orig	2019-02-28 06:54:29 UTC
+++ dpf/dgl/src/Window.cpp
@@ -51,6 +51,10 @@ extern "C" {
 #include "../StandaloneWindow.hpp"
 #include "../../distrho/extra/String.hpp"
 
+#if defined(__FreeBSD__)
+#include <unistd.h>
+#endif
+
 #define FOR_EACH_WIDGET(it) \
   for (std::list<Widget*>::iterator it = fWidgets.begin(); it != fWidgets.end(); ++it)
 
@@ -1216,7 +1220,12 @@ bool Window::openFileBrowser(const FileB
 #  ifdef DISTRHO_OS_LINUX
     if (startDir.isEmpty())
     {
+#if defined(__FreeBSD__)
+        char buf[1024];
+        if (char* const dir_name = ::getwd(buf))
+#else
         if (char* const dir_name = get_current_dir_name())
+#endif
         {
             startDir = dir_name;
             std::free(dir_name);
