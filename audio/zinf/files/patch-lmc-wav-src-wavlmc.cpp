--- lmc/wav/src/wavlmc.cpp.orig	Sat Mar 15 10:01:52 2003
+++ lmc/wav/src/wavlmc.cpp	Thu Aug 21 19:49:36 2003
@@ -49,6 +49,7 @@
 #include "facontext.h"
 #include "log.h"
 #include "debug.h"
+#include "swab.h"
 
 #define DB Debug_v("%s:%d\n",  __FILE__, __LINE__);
 
