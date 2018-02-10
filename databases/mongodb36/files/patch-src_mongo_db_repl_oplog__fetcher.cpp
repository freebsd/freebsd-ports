--- src/mongo/db/repl/oplog_fetcher.cpp.orig	2018-01-18 12:18:49 UTC
+++ src/mongo/db/repl/oplog_fetcher.cpp
@@ -245,7 +245,7 @@ StatusWith<boost::optional<rpc::OplogQue
         if (!metadataResult.isOK()) {
             return metadataResult.getStatus();
         }
-        oqMetadata = boost::make_optional<rpc::OplogQueryMetadata>(metadataResult.getValue());
+        oqMetadata = boost::make_optional(metadataResult.getValue());
     }
     return oqMetadata;
 }
