--- src/dbsc.c.orig	1998-06-08 00:23:35 UTC
+++ src/dbsc.c
@@ -51,6 +51,10 @@
 
 #define DBSC
 
+#ifdef HAVE_SYS_PARAM_H
+#include <sys/param.h>
+#endif
+
 #include <stdio.h>
 #include <stdlib.h>
 #include <string.h>
@@ -69,7 +73,7 @@
 #include <arpa/inet.h>
 #include <errno.h>
 
-#if !defined(bsdi)
+#if (!defined(BSD) || (BSD < 199306))
 #include <malloc.h>
 #endif
 
