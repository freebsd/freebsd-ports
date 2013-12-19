--- gold/stringpool.cc.orig	2010-08-25 10:36:54.000000000 +0200
+++ gold/stringpool.cc	2013-06-22 21:09:24.000000000 +0200
@@ -73,7 +73,10 @@ Stringpool_template<Stringpool_char>::re
 {
   this->key_to_offset_.reserve(n);
 
-#if defined(HAVE_TR1_UNORDERED_MAP)
+#if defined(HAVE_UNORDERED_MAP)
+  this->string_set_.rehash(this->string_set_.size() + n);
+  return;
+#elif defined(HAVE_TR1_UNORDERED_MAP)
   // rehash() implementation is broken in gcc 4.0.3's stl
   //this->string_set_.rehash(this->string_set_.size() + n);
   //return;
@@ -503,7 +506,7 @@ template<typename Stringpool_char>
 void
 Stringpool_template<Stringpool_char>::print_stats(const char* name) const
 {
-#if defined(HAVE_TR1_UNORDERED_MAP) || defined(HAVE_EXT_HASH_MAP)
+#if defined(HAVE_UNORDERED_MAP) || defined(HAVE_TR1_UNORDERED_MAP) || defined(HAVE_EXT_HASH_MAP)
   fprintf(stderr, _("%s: %s entries: %zu; buckets: %zu\n"),
 	  program_name, name, this->string_set_.size(),
 	  this->string_set_.bucket_count());
