--- sal/osl/unx/process.cxx.orig	2023-11-23 12:14:48 UTC
+++ sal/osl/unx/process.cxx
@@ -45,7 +45,7 @@
 #include <machine/param.h>
 #endif
 
-#ifdef IOS
+#if defined (IOS) || defined(FREEBSD)
 #include <signal.h>
 #endif
 
