--- src.orig/state_write.c	Thu Jul 27 19:48:05 2006
+++ src/state_write.c	Thu Jul 27 19:53:08 2006
@@ -41,6 +41,9 @@
 #include "csim.h"  // $$$ for slide switches - really should get from sim instead
 #include "state_io.h"
 
+#ifndef PRIx64
+#define PRIx64 "llx"
+#endif
 
 static void xml_start_element (xmlTextWriterPtr writer, char *element_name)
 {
