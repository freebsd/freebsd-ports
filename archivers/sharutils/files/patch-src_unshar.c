--- src/unshar.c.orig	2020-08-28 17:03:20 UTC
+++ src/unshar.c
@@ -32,6 +32,8 @@
 
 #include "xgetcwd.h"
 
+char const * const program_name = "unshar";
+
 /*
  * FIXME: actually configure this stuff:
  */
