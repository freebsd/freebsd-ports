--- libsql/lexer.c.orig	Wed Aug  6 12:23:40 2003
+++ libsql/lexer.c	Wed Aug  6 12:36:24 2003
@@ -21,7 +21,9 @@
 #include <string.h>
 #include <errno.h>
 #include <stdlib.h>
+#ifdef HAVE_STDINT_H
 #include <stdint.h> /* May break IA64 test-noansi-r */
+#endif
 
 /* end standard C headers. */
 
