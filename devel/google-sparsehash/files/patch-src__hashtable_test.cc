--- src/hashtable_test.cc.orig	2012-02-22 21:49:42.000000000 +0100
+++ src/hashtable_test.cc	2015-02-28 13:31:07.532995000 +0100
@@ -898,7 +898,7 @@
   // Now swap back, using the free-function swap
   // NOTE: MSVC seems to have trouble with this free swap, not quite
   // sure why.  I've given up trying to fix it though.
-#ifdef _MSC_VER
+#if defined(_MSC_VER) || (defined(__clang__) && __clang_major__ >= 3 && __clang_minor__ >= 6)
   other_ht.swap(this->ht_);
 #else
   swap(this->ht_, other_ht);
