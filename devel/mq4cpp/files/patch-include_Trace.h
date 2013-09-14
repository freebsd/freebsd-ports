--- include/Trace.h.orig	2013-09-14 18:46:21.000000000 +0800
+++ include/Trace.h	2013-09-14 18:46:41.000000000 +0800
@@ -92,7 +92,7 @@ class DebugStream : public ostream
 	}
 #else
 #define TRACE(a) \
-	cout << __FILE__ << "(" << __LINE__ << ") #" << (int)pthread_self() << ": " << a << endl;
+	cout << __FILE__ << "(" << __LINE__ << ") #" << pthread_self() << ": " << a << endl;
 #endif
 #else
 #define TRACE(a) ;
