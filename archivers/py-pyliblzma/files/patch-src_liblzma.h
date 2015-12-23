--- src/liblzma.h.orig	2010-02-20 23:07:31 UTC
+++ src/liblzma.h
@@ -8,13 +8,6 @@
 #include <Python.h>
 #include <stdio.h>
 #include <stdlib.h>
-#if defined (__APPLE__) || defined(__FreeBSD__) || \
-    defined(__OpenBSD__) || defined(__NetBSD__) || \
-    defined (__sun) || defined (__svr4__)
-#include <stdlib.h>
-#else
-#include <malloc.h>
-#endif
 #include <string.h>
 #include <inttypes.h>
 #if !defined(linux) && !defined(__sun) && !defined(__svr4__)
