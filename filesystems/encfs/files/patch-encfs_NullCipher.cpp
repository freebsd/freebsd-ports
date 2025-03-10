--- encfs/NullCipher.cpp.orig	2022-05-14 16:04:54 UTC
+++ encfs/NullCipher.cpp
@@ -76,7 +76,7 @@ class NullDestructor {
   NullDestructor &operator=(const NullDestructor &) = delete; // copy assignment
   NullDestructor& operator=(NullDestructor&& other) = delete; // move assignment
 
-  void operator()(NullKey *&) {}
+  void operator()(NullKey *) {}
 };
 std::shared_ptr<AbstractCipherKey> gNullKey(new NullKey(), NullDestructor());
 
