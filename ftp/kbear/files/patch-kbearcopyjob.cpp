--- kbear/base/kbearcopyjob.cpp.orig	Wed May 29 20:37:38 2002
+++ kbear/base/kbearcopyjob.cpp	Wed May 29 20:37:59 2002
@@ -45,7 +45,7 @@
 #include "kbearconnectionmanager.h"
 #include "transfer.h"
 #include <sys/types.h>
-
+#include <assert.h>
 #define REPORT_TIMEOUT 200
 
 #define KIO_ARGS QByteArray packedArgs; QDataStream stream( packedArgs, IO_WriteOnly ); stream
