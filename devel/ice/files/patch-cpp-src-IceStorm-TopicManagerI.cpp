--- cpp.orig/src/IceStorm/TopicManagerI.cpp	2011-06-15 21:43:58.000000000 +0200
+++ cpp/src/IceStorm/TopicManagerI.cpp	2012-09-12 22:14:00.000000000 +0200
@@ -312,7 +312,7 @@ TopicManagerImpl::TopicManagerImpl(const InstancePtr& instance) :
             _sync = _instance->nodeAdapter()->addWithUUID(_syncImpl);
         }
 
-        DatabaseConnectionPtr connection = _databaseCache->getConnection();
+        DatabaseConnectionPtr connection = _databaseCache->newConnection();
 
         // Ensure that the llu counter is present in the log.
         LLUWrapperPtr lluWrapper = _databaseCache->getLLU(connection);
@@ -381,7 +381,7 @@ TopicManagerImpl::create(const string& name)
     {
         try
         {
-            DatabaseConnectionPtr connection = _databaseCache->getConnection();
+            DatabaseConnectionPtr connection = _databaseCache->newConnection();
             TransactionHolder txn(connection);
 
             SubscriberRecordKey key;
@@ -486,7 +486,7 @@ TopicManagerImpl::observerInit(const LogUpdate& llu, const TopicContentSeq& cont
     {
         try
         {
-            DatabaseConnectionPtr connection = _databaseCache->getConnection();
+            DatabaseConnectionPtr connection = _databaseCache->newConnection();
             TransactionHolder txn(connection);
 
             LLUWrapperPtr lluWrapper = _databaseCache->getLLU(connection);
@@ -590,7 +590,7 @@ TopicManagerImpl::observerCreateTopic(const LogUpdate& llu, const string& name)
     {
         try
         {
-            DatabaseConnectionPtr connection = _databaseCache->getConnection();
+            DatabaseConnectionPtr connection = _databaseCache->newConnection();
             TransactionHolder txn(connection);
 
             SubscriberRecordKey key;
@@ -776,7 +776,7 @@ TopicManagerImpl::initMaster(const set<GroupNodeInfo>& slaves, const LogUpdate&
         {
             content.clear();
 
-            DatabaseConnectionPtr connection = _databaseCache->getConnection();
+            DatabaseConnectionPtr connection = _databaseCache->newConnection();
             TransactionHolder txn(connection);
 
             for(map<string, TopicImplPtr>::const_iterator p = _topics.begin(); p != _topics.end(); ++p)
