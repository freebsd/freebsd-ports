--- src/UI/XGUIApp.cpp.orig	2017-04-14 14:21:02 UTC
+++ src/UI/XGUIApp.cpp
@@ -26,6 +26,8 @@
 #include "PlatformUtils.h"
 #include "ObjCUtils.h"
 
+#include <locale.h>
+
 class	XGrinderWin;
 
 #if IBM
