--- extra/yassl/taocrypt/src/integer.cpp.orig	2012-12-17 03:41:47.000000000 +0200
+++ extra/yassl/taocrypt/src/integer.cpp	2012-12-17 03:42:47.000000000 +0200
@@ -73,7 +73,7 @@
 CPP_TYPENAME AlignedAllocator<T>::pointer AlignedAllocator<T>::allocate(
                                            size_type n, const void *)
 {
-    if (n > max_size())
+    if (n > AlignedAllocator<T>::max_size())
         return 0;
     if (n == 0)
         return 0;
