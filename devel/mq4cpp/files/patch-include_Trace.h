--- include/Trace.h.orig	Sat Mar 17 01:42:59 2007
+++ include/Trace.h	Thu Aug  9 17:17:25 2007
@@ -92,7 +92,7 @@
 	}
 #else
 #define TRACE(a) \
-	cout << __FILE__ << "(" << __LINE__ << ") #" << (int)pthread_self() << ": " << a << endl;
+	cout << __FILE__ << "(" << __LINE__ << ") #" << pthread_self() << ": " << a << endl;
 #endif
 #else
 #define TRACE(a) ;
