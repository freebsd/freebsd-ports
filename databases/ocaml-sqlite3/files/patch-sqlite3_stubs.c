--- sqlite3_stubs.c.orig	Mon Feb 27 20:51:46 2006
+++ sqlite3_stubs.c	Mon Feb 27 23:23:43 2006
@@ -24,7 +24,10 @@
 
 #include <stdio.h>
 #include <string.h> 
+/* FIXME: This should go into configure script. */
+#if defined(HAVE_ALLOCA_H)
 #include <alloca.h>
+#endif
 
 #include <caml/mlvalues.h>
 #include <caml/memory.h>
