--- components/supervised_user/core/browser/proto_fetcher.h.orig	2023-10-19 19:58:20 UTC
+++ components/supervised_user/core/browser/proto_fetcher.h
@@ -165,10 +165,18 @@ class ParallelFetchManager {
 
   // Starts the fetch. Underlying fetcher is stored internally, and will be
   // cleaned up after finish or when this manager is destroyed.
+#if defined(__clang__) && (__clang_major__ >= 15) 
   void Fetch(const Request& request, Fetcher::Callback callback);
+#else
+  void Fetch(const Request& request, typename Fetcher::Callback callback);
+#endif
 
  private:
+#if defined(__clang__) && (__clang_major__ >= 15) 
   using KeyType = base::IDMap<std::unique_ptr<Fetcher>>::KeyType;
+#else
+  using KeyType = typename base::IDMap<std::unique_ptr<Fetcher>>::KeyType;
+#endif
 
   // Remove fetcher under key from requests_in_flight_.
   void Remove(KeyType key);
