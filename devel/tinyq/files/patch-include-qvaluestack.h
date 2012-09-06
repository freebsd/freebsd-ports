--- include/qvaluestack.h.orig	2002-10-17 15:08:58.000000000 +0000
+++ include/qvaluestack.h	2012-09-03 22:17:15.000000000 +0000
@@ -50,12 +50,12 @@
 public:
     QValueStack() {}
    ~QValueStack() {}
-    void  push( const T& d ) { append(d); }
+    void  push( const T& d ) { this->append(d); }
     T pop()
     {
 	T elem( this->last() );
 	if ( !this->isEmpty() )
-	    remove( this->fromLast() );
+	   this->remove( this->fromLast() );
 	return elem;
     }
     T& top() { return this->last(); }
