--- dependencies/angelscript/source/as_thread.h.orig	2008-11-20 00:40:34.000000000 +0300
+++ dependencies/angelscript/source/as_thread.h	2009-08-13 07:12:32.000000000 +0400
@@ -66,10 +66,10 @@
 	asCAtomic refCount;
 
 #ifndef AS_NO_THREADS
-	asCThreadLocalData *GetLocalData(asDWORD threadId);
-	void SetLocalData(asDWORD threadId, asCThreadLocalData *tld);
+	asCThreadLocalData *GetLocalData(pthread_t threadId);
+	void SetLocalData(pthread_t threadId, asCThreadLocalData *tld);
 
-	asCMap<asDWORD,asCThreadLocalData*> tldMap;
+	asCMap<pthread_t,asCThreadLocalData*> tldMap;
 	DECLARECRITICALSECTION(criticalSection);
 #else
 	asCThreadLocalData *tld;
