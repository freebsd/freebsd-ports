--- src/utils/FileRecordTools/Records/StrandQueue.h.orig	2015-09-03 04:36:18 UTC
+++ src/utils/FileRecordTools/Records/StrandQueue.h
@@ -30,7 +30,7 @@ public:
 
 private:
 //	static RecordPtrSortFunctor _recSortFunctor;
-	typedef priority_queue<Record *, vector<const Record *>, RecordPtrSortDescFunctor > queueType;
+	typedef priority_queue<Record *, vector<Record *>, RecordPtrSortDescFunctor > queueType;
 	vector<queueType *> _queues;
 	static const int NUM_QUEUES = 3;
 
