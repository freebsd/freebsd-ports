--- src/gui/src/SplashScreen.cpp.orig	2020-06-03 21:33:30 UTC
+++ src/gui/src/SplashScreen.cpp
@@ -32,7 +32,7 @@
 const char* SplashScreen::__class_name = "SplashScreen";
 
 SplashScreen::SplashScreen()
- : QSplashScreen( NULL )
+ : QSplashScreen( (QWidget*)nullptr )
  , Object( __class_name )
 {
 	//INFOLOG( "SplashScreen" );
