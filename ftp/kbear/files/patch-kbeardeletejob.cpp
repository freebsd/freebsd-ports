--- kbear/base/kbeardeletejob.cpp.orig	Wed May 29 20:35:16 2002
+++ kbear/base/kbeardeletejob.cpp	Wed May 29 20:35:47 2002
@@ -30,7 +30,7 @@
 #include "kbeardeletejob.h"
 #include "kbearlistjob.h"
 #include "kbearconnectionmanager.h"
-
+#include <assert.h>
 #define REPORT_TIMEOUT 200
 
 #define KIO_ARGS QByteArray packedArgs; QDataStream stream( packedArgs, IO_WriteOnly ); stream
