--- long-hashtable.c.orig	2020-06-04 23:59:33 UTC
+++ long-hashtable.c
@@ -22,7 +22,7 @@
 #include <string.h>
 
 #ifndef MACOS
-#ifndef FREEBSD
+#ifndef __FreeBSD__
 #include <malloc.h>
 #endif
 #endif
