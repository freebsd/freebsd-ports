--- src/utils/dlvclient/dlvclient.cpp.orig	2020-06-04 12:27:44 UTC
+++ src/utils/dlvclient/dlvclient.cpp
@@ -26,8 +26,7 @@
 #include <QHostAddress>
 #include <QUrl>
 #include <QDebug>
-#include "qjsonrpc/src/json/qjson_export.h"
-#include "qjsonrpc/src/json/qjsondocument.h"
+#include <qjsondocument.h>
 #include "qjsonrpc/src/qjsonrpcservicereply.h"
 //lite_memory_check_begin
 #if defined(WIN32) && defined(_MSC_VER) &&  defined(_DEBUG)
