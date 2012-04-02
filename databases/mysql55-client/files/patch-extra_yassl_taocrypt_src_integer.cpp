--- extra/yassl/taocrypt/src/integer.cpp.orig	2012-04-02 09:37:09.000000000 +0200
+++ extra/yassl/taocrypt/src/integer.cpp	2012-04-02 09:37:41.000000000 +0200
@@ -73,7 +73,7 @@
 CPP_TYPENAME AlignedAllocator<T>::pointer AlignedAllocator<T>::allocate(
                                            size_type n, const void *)
 {
-    if (n > max_size())
+    if (n > AlignedAllocator<T>::max_size())
         return 0;
     if (n == 0)
         return 0;
