--- lib/signature.c	Sat Feb  2 13:55:49 2002
+++ lib/signature.c	Wed Mar 27 10:21:31 2002
@@ -11,6 +11,10 @@
  * size key you like).  We also honor PGPPATH finally.
  */
 
+#ifdef __FreeBSD__
+extern char **environ;
+#endif
+
 #include "system.h"
 
 #include "rpmio_internal.h"
