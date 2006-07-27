--- src.orig/state_read.c	Thu Jul 27 19:48:05 2006
+++ src/state_read.c	Thu Jul 27 19:52:02 2006
@@ -42,6 +42,9 @@
 #include "csim.h"  // $$$ for slide switches - really should get from sim instead
 #include "state_io.h"
 
+#ifndef PRIx64
+#define PRIx64 "llx"
+#endif 
 
 #define unused __attribute__((unused))
 
