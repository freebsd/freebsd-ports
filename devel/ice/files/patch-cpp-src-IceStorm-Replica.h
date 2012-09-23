--- cpp.orig/src/IceStorm/Replica.h	2011-06-15 21:43:58.000000000 +0200
+++ cpp/src/IceStorm/Replica.h	2012-09-10 11:43:58.000000000 +0200
@@ -23,9 +23,9 @@ struct GroupNodeInfo
     GroupNodeInfo(int i, LogUpdate l, const Ice::ObjectPrx& o = Ice::ObjectPrx());
     bool operator<(const GroupNodeInfo& rhs) const;
     bool operator==(const GroupNodeInfo& rhs) const;
-    const int id;
-    const LogUpdate llu;
-    const Ice::ObjectPrx observer;
+    int id;
+    LogUpdate llu;
+    Ice::ObjectPrx observer;
 };
 
 class Replica : virtual public IceUtil::Shared
