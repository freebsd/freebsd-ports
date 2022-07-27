--- plugins/editor/external/vstgui4/vstgui/lib/platform/linux/x11fileselector.cpp.orig	2022-07-27 03:15:46 UTC
+++ plugins/editor/external/vstgui4/vstgui/lib/platform/linux/x11fileselector.cpp
@@ -14,6 +14,8 @@
 #include <cassert>
 extern "C" { extern char **environ; }
 
+#define execvpe(a, b, c) execvp(a, b)
+
 //------------------------------------------------------------------------
 namespace VSTGUI {
 namespace X11 {
