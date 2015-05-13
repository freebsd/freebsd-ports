--- code/apis/JoystickManager.cpp.orig	2015-04-11 22:15:55 UTC
+++ code/apis/JoystickManager.cpp
@@ -65,8 +65,10 @@ bool JoyMan::IsInitialized() {
 */
 bool JoyMan::Initialize() {
 	if ( JoyMan::IsInitialized() ) {
+#if USE_JOYSTICK
 		wxLogDebug(_T("JoyMan already initialized with %d joysticks"),
 			joysticks.Count());
+#endif
 		return true;
 	}
 
