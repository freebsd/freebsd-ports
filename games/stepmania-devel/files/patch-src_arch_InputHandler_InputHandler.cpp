--- src/arch/InputHandler/InputHandler.cpp.orig	2007-03-26 06:06:37.000000000 +0300
+++ src/arch/InputHandler/InputHandler.cpp	2008-01-30 23:20:18.000000000 +0200
@@ -6,6 +6,7 @@
 #include "LocalizedString.h"
 #include "arch/arch_default.h"
 #include "InputHandler_MonkeyKeyboard.h"
+#include "InputHandler_Linux_Joystick.h"
 #include "Foreach.h"
 
 void InputHandler::UpdateTimer()
@@ -190,6 +191,7 @@
 
 	// Always add
 	Add.push_back( new InputHandler_MonkeyKeyboard );
+	Add.push_back( new InputHandler_Linux_Joystick );
 }
 
 
