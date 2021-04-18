- fix missing include, see https://github.com/steinbergmedia/vst3sdk/issues/80

--- vstgui4/vstgui/lib/platform/linux/x11fileselector.cpp.orig	2020-08-20 14:14:27 UTC
+++ vstgui4/vstgui/lib/platform/linux/x11fileselector.cpp
@@ -6,6 +6,9 @@
 #include <unistd.h>
 #include <string>
 
+#define _WITH_GETLINE // this is still required on FreeBSD 11
+#include <stdio.h>
+
 //------------------------------------------------------------------------
 namespace VSTGUI {
 namespace X11 {
