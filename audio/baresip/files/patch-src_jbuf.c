--- src/jbuf.c.orig	2025-09-10 13:06:07 UTC
+++ src/jbuf.c
@@ -7,6 +7,10 @@
  * Copyright (C) 2010 Creytiv.com
  */
 
+#ifndef ETIME
+#define ETIME ETIMEDOUT
+#endif
+
 #undef RE_TRACE_ENABLED
 #if JBUF_TRACE
 #define RE_TRACE_ENABLED 1
