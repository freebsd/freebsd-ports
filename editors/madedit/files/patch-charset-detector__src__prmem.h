--- ./charset-detector/src/prmem.h.orig	2011-03-22 16:53:02.938216470 -0700
+++ ./charset-detector/src/prmem.h	2011-03-22 16:53:03.708221682 -0700
@@ -37,7 +37,9 @@
 #ifndef nsDummyPrmem_h__
 #define nsDummyPrmem_h__
 
+#pragma GCC visibility push(default)
 #include <stdlib.h>
+#pragma GCC visibility pop
 
 inline void* PR_Malloc(size_t len)
 {
