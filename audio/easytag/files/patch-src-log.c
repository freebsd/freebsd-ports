--- src/log.c.orig	2013-02-05 23:42:37.000000000 +0100
+++ src/log.c	2013-08-07 10:52:19.934047139 +0200
@@ -39,6 +39,11 @@
 #include "win32/win32dep.h"
 #endif /* G_OS_WIN32 */
 
+/* Disable -Wformat-nonliteral warning for this source file, since
+** all calls have safe format strings coming. */
+#ifdef __clang__
+#pragma clang diagnostic ignored "-Wformat-nonliteral"
+#endif
 
 /****************
  * Declarations *
