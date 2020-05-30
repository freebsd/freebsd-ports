--- src/libsync/networkjobs.cpp.orig	2020-05-30 08:02:56 UTC
+++ src/libsync/networkjobs.cpp
@@ -31,6 +31,7 @@
 #include <QJsonObject>
 #ifndef TOKEN_AUTH_ONLY
 #include <QPainter>
+#include <QPainterPath>
 #endif
 
 #include "networkjobs.h"
