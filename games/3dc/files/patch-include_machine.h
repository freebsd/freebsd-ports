--- ../include/machine.h.orig	Mon May 31 12:57:09 1999
+++ ../include/machine.h	Mon May 31 12:57:36 1999
@@ -35,7 +35,7 @@
 #include <ulimit.h>
 #endif
 
-#ifdef __alpha__
+#if defined(__alpha__) && !defined(__FreeBSD__)
 #include <alloca.h>
 #endif /* __alpha__ */
 
