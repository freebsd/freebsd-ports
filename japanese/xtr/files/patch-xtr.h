--- src/xtr.h.orig	Wed Jul 23 17:02:22 2003
+++ src/xtr.h	Wed Jul 23 17:04:42 2003
@@ -493,10 +493,12 @@
 #endif
 #endif
 
+#ifndef __P
 #ifdef __STDC__
 #define __P(args) args
 #else
 #define __P(args) ()
+#endif
 #endif
 
 typedef int (*sffnp_t) __P((uchar *d));
