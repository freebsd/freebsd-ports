https://jira.mongodb.org/browse/SERVER-32516
https://github.com/mongodb/mongo/commit/3c34eda8d8a3

--- src/mongo/db/repl/oplog_fetcher.cpp.orig	2017-09-07 19:28:48 UTC
+++ src/mongo/db/repl/oplog_fetcher.cpp
@@ -265,7 +265,7 @@ StatusWith<boost::optional<rpc::OplogQueryMetadata>> p
         if (!metadataResult.isOK()) {
             return metadataResult.getStatus();
         }
-        oqMetadata = boost::make_optional<rpc::OplogQueryMetadata>(metadataResult.getValue());
+        oqMetadata = boost::make_optional(metadataResult.getValue());
     }
     return oqMetadata;
 }
