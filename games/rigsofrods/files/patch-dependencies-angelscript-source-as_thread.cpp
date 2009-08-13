--- dependencies/angelscript/source/as_thread.cpp.orig	2008-11-20 00:40:26.000000000 +0300
+++ dependencies/angelscript/source/as_thread.cpp	2009-08-13 07:15:41.000000000 +0400
@@ -94,7 +94,7 @@
 	ENTERCRITICALSECTION(criticalSection);
 
 	// Delete all thread local datas
-	asSMapNode<asDWORD,asCThreadLocalData*> *cursor = 0;
+	asSMapNode<pthread_t,asCThreadLocalData*> *cursor = 0;
 	if( tldMap.MoveFirst(&cursor) )
 	{
 		do
@@ -121,14 +121,14 @@
 #ifndef AS_NO_THREADS
 	int r = 0;
 #if defined AS_POSIX_THREADS
-	asDWORD id = (asDWORD)pthread_self();
+	pthread_t id = pthread_self();
 #elif defined AS_WINDOWS_THREADS
 	asDWORD id = GetCurrentThreadId();
 #endif
 
 	ENTERCRITICALSECTION(criticalSection);
 
-	asSMapNode<asDWORD,asCThreadLocalData*> *cursor = 0;
+	asSMapNode<pthread_t,asCThreadLocalData*> *cursor = 0;
 	if( tldMap.MoveTo(&cursor, id) )
 	{
 		asCThreadLocalData *tld = tldMap.GetValue(cursor);
@@ -163,13 +163,13 @@
 }
 
 #ifndef AS_NO_THREADS
-asCThreadLocalData *asCThreadManager::GetLocalData(asDWORD threadId)
+asCThreadLocalData *asCThreadManager::GetLocalData(pthread_t threadId)
 {
 	asCThreadLocalData *tld = 0;
 
 	ENTERCRITICALSECTION(criticalSection);
 
-	asSMapNode<asDWORD,asCThreadLocalData*> *cursor = 0;
+	asSMapNode<pthread_t,asCThreadLocalData*> *cursor = 0;
 	if( tldMap.MoveTo(&cursor, threadId) )
 		tld = tldMap.GetValue(cursor);
 
@@ -178,7 +178,7 @@
 	return tld;
 }
 
-void asCThreadManager::SetLocalData(asDWORD threadId, asCThreadLocalData *tld)
+void asCThreadManager::SetLocalData(pthread_t threadId, asCThreadLocalData *tld)
 {
 	ENTERCRITICALSECTION(criticalSection);
 
@@ -192,7 +192,7 @@
 {
 #ifndef AS_NO_THREADS
 #if defined AS_POSIX_THREADS
-	asDWORD id = (asDWORD)pthread_self();
+	pthread_t id = pthread_self();
 #elif defined AS_WINDOWS_THREADS
 	asDWORD id = GetCurrentThreadId();
 #endif
