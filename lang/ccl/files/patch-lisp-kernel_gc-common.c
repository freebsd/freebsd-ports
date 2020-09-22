--- lisp-kernel/gc-common.c.orig	2020-04-19 21:32:56 UTC
+++ lisp-kernel/gc-common.c
@@ -24,6 +24,9 @@
 #include <stdlib.h>
 #include <string.h>
 
+LispObj *GCrelocptr, *global_reloctab;
+LispObj GCfirstunmarked;
+
 #ifndef WINDOWS
 #include <sys/time.h>
 #endif
