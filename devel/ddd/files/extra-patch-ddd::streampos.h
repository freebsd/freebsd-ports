--- ddd/streampos.h.orig	Mon Jan 17 09:53:42 2000
+++ ddd/streampos.h	Fri Jun  6 03:49:41 2003
@@ -40,7 +40,9 @@
 #include "config.h"
 
 #if !HAVE_STREAMPOS
+#ifndef __FreeBSD__
 typedef long streampos;
+#endif
 #endif
 
 #endif // _DDD_streampos_h
