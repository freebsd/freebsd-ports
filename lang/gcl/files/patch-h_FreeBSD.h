--- h/FreeBSD.h	2004-06-12 12:28:15.000000000 -0400
+++ h/FreeBSD.h	2009-12-07 12:07:37.000000000 -0500
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
@@ -68,7 +73,11 @@
 #ifdef CLOCKS_PER_SEC
 #define HZ CLOCKS_PER_SEC
 #else
-#define HZ 128
+#	ifdef _SC_CLK_TCK	/* Define HZ properly: */
+#		define HZ	sysconf(_SC_CLK_TCK)
+#	elif	!defined(HZ)
+#		define HZ	128
+#	endif
 #endif
 /* #define ss_base ss_sp */
 
