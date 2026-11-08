--- contrib/SeqLib/SeqLib/GenomicRegionCollection.cpp.orig	2026-09-01 21:13:10 UTC
+++ contrib/SeqLib/SeqLib/GenomicRegionCollection.cpp
@@ -8,6 +8,7 @@
 #include <stdexcept>
 #include <algorithm>
 #include <zlib.h>
+#include <random>
 
 #define GZBUFFER 65472
 
@@ -75,7 +76,9 @@ namespace SeqLib {
   
   template<class T>
   void GenomicRegionCollection<T>::Shuffle() {
-    std::random_shuffle ( m_grv->begin(), m_grv->end() );
+    std::random_device rd;
+    std::mt19937 g(rd());
+    std::shuffle ( m_grv->begin(), m_grv->end(), g );
   }
 
   template<class T>
