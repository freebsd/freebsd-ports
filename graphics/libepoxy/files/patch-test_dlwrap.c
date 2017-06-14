--- test/dlwrap.c.orig	2017-03-28 08:56:46 UTC
+++ test/dlwrap.c
@@ -34,6 +34,8 @@
 
 /* dladdr is a glibc extension */
 #define _GNU_SOURCE
+/* FreeBSD needs this to make asprintf() and dlvsym() visible */
+#define __BSD_VISIBLE 1
 #include <dlfcn.h>
 
 #include <stdbool.h>
