--- src/Sound.hpp.orig	Sat Jun  7 11:12:19 2003
+++ src/Sound.hpp	Sat Jun  7 11:12:43 2003
@@ -19,6 +19,8 @@
 #ifndef SOUND_HPP
 #define SOUND_HPP
 
+#define AFMT_S16_NE AFMT_S16_LE
+
 #include <qobject.h>
 #include <qstring.h>
 #include <qsocketnotifier.h>
