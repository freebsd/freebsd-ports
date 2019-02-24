--- fdbclient/BlobStore.h.orig	2019-02-23 13:23:11 UTC
+++ fdbclient/BlobStore.h
@@ -36,7 +36,7 @@ class BlobStoreEndpoint : public ReferenceCounted<Blob
 	struct Stats {
 		Stats() : requests_successful(0), requests_failed(0), bytes_sent(0) {}
 		Stats operator-(const Stats &rhs);
-		void clear() { memset(this, sizeof(*this), 0); }
+		void clear() { memset(this, 0, sizeof(*this)); }
 		json_spirit::mObject getJSON();
 
 		int64_t requests_successful;
