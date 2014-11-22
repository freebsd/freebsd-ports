--- src/database/telnetclient.cpp_orig	2014-11-16 10:28:15.984904777 +0100
+++ src/database/telnetclient.cpp	2014-11-16 10:31:37.429891480 +0100
@@ -4,8 +4,11 @@
 
 #include "telnetclient.h"
 
-#include <QTcpSocket>
+#include <QDebug>
 #include <QHostAddress>
+#include <QRegExp>
+#include <QStringList>
+#include <QTcpSocket>
 
 #define DEBUG_TELNET
 //#undef DEBUG_TELNET
