--- components/supervised_user/core/browser/proto_fetcher.cc.orig	2023-11-29 21:40:00 UTC
+++ components/supervised_user/core/browser/proto_fetcher.cc
@@ -525,8 +525,11 @@ class RetryingFetcherImpl final : public DeferredFetch
   // Not copyable.
   RetryingFetcherImpl(const RetryingFetcherImpl&) = delete;
   RetryingFetcherImpl& operator=(const RetryingFetcherImpl&) = delete;
-
+#if defined(__clang__) && (__clang_major__ >= 15)
   void Start(ProtoFetcher<Response>::Callback callback) override {
+#else
+  void Start(typename ProtoFetcher<Response>::Callback callback) override {
+#endif
     callback_ = std::move(callback);
     Retry();
   }
@@ -564,7 +567,11 @@ class RetryingFetcherImpl final : public DeferredFetch
   }
 
   // Client callback.
+#if defined(__clang__) && (__clang_major__ >= 15)
   ProtoFetcher<Response>::Callback callback_;
+#else
+  typename ProtoFetcher<Response>::Callback callback_;
+#endif
 
   // Retry controls.
   base::OneShotTimer timer_;
@@ -707,7 +714,11 @@ void ParallelFetchManager<Request, Response>::Fetch(
 template <typename Request, typename Response>
 void ParallelFetchManager<Request, Response>::Fetch(
     const Request& request,
+#if defined(__clang__) && (__clang_major__ >= 15)
     Fetcher::Callback callback) {
+#else
+    typename Fetcher::Callback callback) {
+#endif
   CHECK(callback) << "Use base::DoNothing() instead of empty callback.";
   KeyType key = requests_in_flight_.Add(MakeFetcher(request));
   requests_in_flight_.Lookup(key)->Start(
