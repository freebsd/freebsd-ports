--- kbear/base/kbearfilecopyjob.cpp.orig	Wed May 29 20:39:12 2002
+++ kbear/base/kbearfilecopyjob.cpp	Wed May 29 20:39:30 2002
@@ -40,7 +40,7 @@
 #include "kbearfilecopyjob.h"
 #include "kbearconnectionmanager.h"
 #include <sys/types.h>
-
+#include <assert.h>
 #define KIO_ARGS QByteArray packedArgs; QDataStream stream( packedArgs, IO_WriteOnly ); stream
 
 class KBearFileCopyJob::KBearFileCopyJobPrivate
