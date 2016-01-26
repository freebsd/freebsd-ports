--- coreSQLiteStudio/common/utils.cpp.orig	2016-01-21 10:31:10 UTC
+++ coreSQLiteStudio/common/utils.cpp
@@ -2,6 +2,7 @@
 #include "common/global.h"
 #include "dbobjecttype.h"
 #include "rsa/RSA.h"
+#include <QDataStream>
 #include <QTextCodec>
 #include <QString>
 #include <QSet>
