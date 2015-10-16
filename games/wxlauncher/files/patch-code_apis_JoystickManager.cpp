--- code/apis/JoystickManager.cpp.orig	2015-08-26 04:54:06 UTC
+++ code/apis/JoystickManager.cpp
@@ -84,9 +84,9 @@ bool JoyMan::IsInitialized() {
 \sa JoyMan::WasCompiledIn()
 */
 bool JoyMan::Initialize(ApiType apiType) {
+#if USE_JOYSTICK
 	currentApi = apiType;
 
-#if USE_JOYSTICK
 	if ( JoyMan::IsInitialized() ) {
 		wxLogDebug(_T("JoyMan already initialized"));
 		return true;
