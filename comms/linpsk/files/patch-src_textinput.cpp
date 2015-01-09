--- src/textinput.cpp.orig	2015-01-07 06:35:27.000000000 -0800
+++ src/textinput.cpp	2015-01-07 06:35:36.000000000 -0800
@@ -22,7 +22,7 @@
 extern Parameter settings;
 extern int errno;
 
-TextInput::TextInput ( int ptt = -1 ) : Input ( ptt )
+TextInput::TextInput ( int ptt ) : Input ( ptt )
 {
 }
 TextInput::~TextInput()
