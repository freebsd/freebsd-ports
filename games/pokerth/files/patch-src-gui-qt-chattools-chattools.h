--- src/gui/qt/chattools/chattools.h.orig	2013-12-22 17:58:01.952816000 +0100
+++ src/gui/qt/chattools/chattools.h	2013-12-23 12:50:56.420547009 +0100
@@ -33,8 +33,10 @@
 
 #include <string>
 #include <QtCore>
-#include <QtWidgets>
 #include <QtGui>
+#if QT_VERSION >= 0x050000
+#include <QtWidgets>
+#endif
 #include <boost/shared_ptr.hpp>
 
 enum ChatType { INET_LOBBY_CHAT, LAN_LOBBY_CHAT, INGAME_CHAT };
