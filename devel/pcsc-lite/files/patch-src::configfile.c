--- src/configfile.c.bak	Sun Jun  1 23:43:39 2003
+++ src/configfile.c	Sun Jun  1 23:43:59 2003
@@ -20,7 +20,9 @@
 #include <string.h>
 #include <errno.h>
 #include <stdlib.h>
+#ifdef HAVE_STDINT_H
 #include <stdint.h> /* May break IA64 test-noansi-r */
+#endif
 
 /* end standard C headers. */
 
