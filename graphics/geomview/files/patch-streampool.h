--- src/lib/oogl/refcomm/streampool.h.orig	Mon Aug 12 17:15:10 2002
+++ src/lib/oogl/refcomm/streampool.h	Mon Aug 12 17:15:15 2002
@@ -29,7 +29,7 @@
 #include "config.h"
 #endif
 
-#ifdef AIX
+#if AIX
 # include <sys/select.h>  /* RS-6000 needs this */
 #endif
 
