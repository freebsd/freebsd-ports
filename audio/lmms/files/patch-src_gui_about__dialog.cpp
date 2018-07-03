--- src/gui/about_dialog.cpp.orig	2018-07-02 13:46:00 UTC
+++ src/gui/about_dialog.cpp
@@ -46,7 +46,7 @@ aboutDialog::aboutDialog() :
 					arg( PLATFORM ).
 					arg( MACHINE ).
 					arg( QT_VERSION_STR ).
-					arg( GCC_VERSION ) );
+					arg( __VERSION__ ) );
 
 	authorLabel->setPlainText( embed::getText( "AUTHORS" ) );
 
