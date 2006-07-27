--- src.orig/proc_nut.c	Thu Jul 27 18:10:44 2006
+++ src/proc_nut.c	Thu Jul 27 18:11:41 2006
@@ -38,6 +38,9 @@
 #include "proc_nut.h"
 #include "dis_nut.h"
 
+#ifndef PRId64
+#define PRId64 "lld"
+#endif
 
 #define KBD_RELEASE_DEBOUNCE_CYCLES 32
 
