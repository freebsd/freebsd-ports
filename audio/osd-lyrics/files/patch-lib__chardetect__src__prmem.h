--- lib/chardetect/src/prmem.h.orig
+++ lib/chardetect/src/prmem.h
@@ -37,7 +37,9 @@
 #ifndef nsDummyPrmem_h__
 #define nsDummyPrmem_h__
 
+#pragma GCC visibility push(default)
 #include <stdlib.h>
+#pragma GCC visibility pop
 
 inline void* PR_Malloc(size_t len)
 {
