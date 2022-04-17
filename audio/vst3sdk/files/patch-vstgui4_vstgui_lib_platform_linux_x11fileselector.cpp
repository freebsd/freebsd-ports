- fix missing include, see https://github.com/steinbergmedia/vst3sdk/issues/80

--- vstgui4/vstgui/lib/platform/linux/x11fileselector.cpp.orig	2021-12-07 16:20:00 UTC
+++ vstgui4/vstgui/lib/platform/linux/x11fileselector.cpp
@@ -14,6 +14,8 @@
 #include <cassert>
 extern "C" { extern char **environ; }
 
+#include <stdio.h>
+
 //------------------------------------------------------------------------
 namespace VSTGUI {
 namespace X11 {
