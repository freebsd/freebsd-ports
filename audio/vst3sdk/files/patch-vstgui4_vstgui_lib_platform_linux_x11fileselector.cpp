- fix missing include, see https://github.com/steinbergmedia/vst3sdk/issues/80

--- vstgui4/vstgui/lib/platform/linux/x11fileselector.cpp.orig	2021-04-15 16:36:46 UTC
+++ vstgui4/vstgui/lib/platform/linux/x11fileselector.cpp
@@ -6,6 +6,8 @@
 #include <unistd.h>
 #include <string>
 
+#include <stdio.h>
+
 //------------------------------------------------------------------------
 namespace VSTGUI {
 namespace X11 {
