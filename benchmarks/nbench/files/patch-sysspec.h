--- sysspec.h.orig	2003-02-19 21:37:21 UTC
+++ sysspec.h
@@ -33,7 +33,7 @@
 
 #include "nmglobal.h"
 
-#if !defined(MAC) && !defined(OSX)
+#if !defined(MAC) && !defined(__STDC__)
 #include <malloc.h>
 #endif
 
