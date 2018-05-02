--- fdbclient/MultiVersionAssignmentVars.h.orig	2018-04-29 11:43:19 UTC
+++ fdbclient/MultiVersionAssignmentVars.h
@@ -135,7 +135,7 @@ public:
 	~DLThreadSingleAssignmentVar() {
 		lock.assertNotEntered();
 		if(f) {
-			ASSERT(futureRefCount == 1);
+			ASSERT_ABORT(futureRefCount == 1);
 			api->futureDestroy(f);
 		}
 	}
