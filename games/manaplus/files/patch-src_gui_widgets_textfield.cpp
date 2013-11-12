--- src/gui/widgets/textfield.cpp.orig	2013-11-12 08:08:20.000000000 +0100
+++ src/gui/widgets/textfield.cpp	2013-11-12 08:08:36.000000000 +0100
@@ -23,6 +23,7 @@
 #include "gui/widgets/textfield.h"
 
 #include "client.h"
+#include "mouseinput.h"
 
 #ifdef ANDROID
 #include "input/inputmanager.h"
