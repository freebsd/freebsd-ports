--- ocr-utils/enumerator.h.orig	2009-05-31 20:18:41.000000000 +0000
+++ ocr-utils/enumerator.h
@@ -32,6 +32,10 @@
 #include <memory.h>
 #include "ocropus.h"
 
+inline int Hash_hash(int x) {
+    return x;
+}
+
 template <class T>
 inline void memswap(T &a,T &b) {
     char buf[sizeof (T)];
@@ -102,10 +106,6 @@ struct EnumHash {
     }
 };
 
-inline int Hash_hash(int x) {
-    return x;
-}
-
 struct Enumerator {
     int n;
     EnumHash<int,int> translation;
