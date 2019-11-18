--- table/get_context.h.orig	2019-10-30 17:32:00 UTC
+++ table/get_context.h
@@ -88,7 +88,6 @@ class GetContext {
              ReadCallback* callback = nullptr, bool* is_blob_index = nullptr,
              uint64_t tracing_get_id = 0);
 
-  GetContext() = default;
 
   // This can be called to indicate that a key may be present, but cannot be
   // confirmed due to IO not allowed
