--- src/hash.h.orig	Thu Nov 27 00:33:32 2003
+++ src/hash.h	Thu Nov 27 00:35:25 2003
@@ -23,6 +23,7 @@
 #define HASH_H
 
 #include <stdio.h>
+#include <unistd.h>
 
 typedef struct HASH_T *HASH;
 
