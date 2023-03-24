--- src/sip/auth.c.orig	2022-10-01 08:24:34 UTC
+++ src/sip/auth.c
@@ -3,6 +3,9 @@
  *
  * Copyright (C) 2010 Creytiv.com
  */
+#ifndef ETIME
+#define ETIME ETIMEDOUT
+#endif
 #include <time.h>
 #include <string.h>
 #include <re_types.h>
