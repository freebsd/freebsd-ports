--- src/openhbci/core/transaction.cpp.orig	Sun Jul 20 16:02:04 2003
+++ src/openhbci/core/transaction.cpp	Sun Jul 20 16:02:48 2003
@@ -34,6 +34,7 @@
 #include <config.h>
 #endif
 
+#include <assert.h>
 #include "transaction.h"
 #include "hbcistring.h"
 
