--- cpp/src/FreezeScript/transformdb.cpp.orig	2022-03-31 17:41:42 UTC
+++ cpp/src/FreezeScript/transformdb.cpp
@@ -766,8 +766,8 @@ run(const Ice::StringSeq& originalArgs, const Ice::Com
     //
     // Transform the database.
     //
-    DbEnv dbEnv(0);
-    DbEnv dbEnvNew(0);
+    DbEnv dbEnv((u_int32_t)0);
+    DbEnv dbEnvNew((u_int32_t)0);
     Freeze::TransactionPtr txNew;
     Freeze::ConnectionPtr connection;
     Freeze::ConnectionPtr connectionNew;
