--- cpp.orig/src/IceStorm/TopicI.cpp	2011-06-15 21:43:58.000000000 +0200
+++ cpp/src/IceStorm/TopicI.cpp	2012-09-12 22:14:00.000000000 +0200
@@ -666,7 +666,7 @@ TopicImpl::subscribe(const QoS& origQoS, const Ice::ObjectPrx& obj)
         {
             try
             {
-                DatabaseConnectionPtr connection = _databaseCache->getConnection();
+                DatabaseConnectionPtr connection = _databaseCache->newConnection();
                 TransactionHolder txn(connection);
 
                 SubscriberRecordKey key;
@@ -703,7 +703,7 @@ TopicImpl::subscribe(const QoS& origQoS, const Ice::ObjectPrx& obj)
     {
         try
         {
-            DatabaseConnectionPtr connection = _databaseCache->getConnection();
+            DatabaseConnectionPtr connection = _databaseCache->newConnection();
             TransactionHolder txn(connection);
 
             SubscriberRecordKey key;
@@ -788,7 +788,7 @@ TopicImpl::subscribeAndGetPublisher(const QoS& qos, const Ice::ObjectPrx& obj)
     {
         try
         {
-            DatabaseConnectionPtr connection = _databaseCache->getConnection();
+            DatabaseConnectionPtr connection = _databaseCache->newConnection();
             TransactionHolder txn(connection);
 
             SubscriberRecordKey key;
@@ -912,7 +912,7 @@ TopicImpl::link(const TopicPrx& topic, Ice::Int cost)
     {
         try
         {
-            DatabaseConnectionPtr connection = _databaseCache->getConnection();
+            DatabaseConnectionPtr connection = _databaseCache->newConnection();
             TransactionHolder txn(connection);
 
             SubscriberRecordKey key;
@@ -1311,7 +1311,7 @@ TopicImpl::observerAddSubscriber(const LogUpdate& llu, const SubscriberRecord& r
     {
         try
         {
-            DatabaseConnectionPtr connection = _databaseCache->getConnection();
+            DatabaseConnectionPtr connection = _databaseCache->newConnection();
             TransactionHolder txn(connection);
 
             SubscriberRecordKey key;
@@ -1380,7 +1380,7 @@ TopicImpl::observerRemoveSubscriber(const LogUpdate& llu, const Ice::IdentitySeq
     {
         try
         {
-            DatabaseConnectionPtr connection = _databaseCache->getConnection();
+            DatabaseConnectionPtr connection = _databaseCache->newConnection();
             TransactionHolder txn(connection);
 
             for(Ice::IdentitySeq::const_iterator id = ids.begin(); id != ids.end(); ++id)
@@ -1456,7 +1456,7 @@ TopicImpl::destroyInternal(const LogUpdate& origLLU, bool master)
     {
         try
         {
-            DatabaseConnectionPtr connection = _databaseCache->getConnection();
+            DatabaseConnectionPtr connection = _databaseCache->newConnection();
             TransactionHolder txn(connection);
 
             // Erase all subscriber records and the topic record.
@@ -1531,7 +1531,7 @@ TopicImpl::removeSubscribers(const Ice::IdentitySeq& ids)
     {
         try
         {
-            DatabaseConnectionPtr connection = _databaseCache->getConnection();
+            DatabaseConnectionPtr connection = _databaseCache->newConnection();
             TransactionHolder txn(connection);
 
             for(Ice::IdentitySeq::const_iterator id = ids.begin(); id != ids.end(); ++id)
