--- cpp/src/FreezeScript/DumpDB.cpp.orig	2022-03-31 17:50:52 UTC
+++ cpp/src/FreezeScript/DumpDB.cpp
@@ -481,7 +481,7 @@ run(const Ice::StringSeq& originalArgs, const Ice::Com
     FreezeScript::ObjectFactoryPtr objectFactory = new FreezeScript::ObjectFactory;
     communicator->addObjectFactory(objectFactory, "");
 
-    DbEnv dbEnv(0);
+    DbEnv dbEnv((u_int32_t)0);
     DbTxn* txn = 0;
     Freeze::ConnectionPtr connection;
     int status = EXIT_SUCCESS;
