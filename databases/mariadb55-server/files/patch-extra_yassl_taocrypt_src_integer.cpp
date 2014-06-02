--- extra/yassl/taocrypt/src/integer.cpp.orig	2014-04-15 14:02:39.000000000 +0300
+++ extra/yassl/taocrypt/src/integer.cpp	2014-05-16 17:00:15.000000000 +0300
@@ -75,7 +75,7 @@
 CPP_TYPENAME AlignedAllocator<T>::pointer AlignedAllocator<T>::allocate(
                                            size_type n, const void *)
 {
-    if (n > this->max_size())
+    if (n > AlignedAllocator<T>::max_size())
         return 0;
     if (n == 0)
         return 0;
