Index: h/FreeBSD.h
===================================================================
RCS file: /cvsroot/gcl/gcl/h/FreeBSD.h,v
retrieving revision 1.2.6.2.2.2
diff -u -d -r1.2.6.2.2.2 FreeBSD.h
--- h/FreeBSD.h	12 Jun 2004 16:28:15 -0000	1.2.6.2.2.2
+++ h/FreeBSD.h	18 Aug 2004 16:29:43 -0000
@@ -32,6 +32,11 @@
 #endif
 #include "linux.h"
 
+#if defined(SET_SESSION_ID)
+#undef SET_SESSION_ID
+#endif
+#define SET_SESSION_ID() (setpgrp(0,0) ? -1 : 0)
+
 #if defined(__i386__)
 #define I386
 #endif
