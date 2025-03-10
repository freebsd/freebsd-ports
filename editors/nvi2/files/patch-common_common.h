--- common/common.h.orig	2023-09-25 08:47:42 UTC
+++ common/common.h
@@ -17,6 +17,7 @@
 #include <db.h>
 #endif
 #include <regex.h>		/* May refer to the bundled regex. */
+#include <stdint.h>
 
 /*
  * Forward structure declarations.  Not pretty, but the include files
