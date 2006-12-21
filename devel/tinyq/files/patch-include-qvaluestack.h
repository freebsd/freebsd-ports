--- include/qvaluestack.h.orig	Thu Dec 21 20:51:31 2006
+++ include/qvaluestack.h	Thu Dec 21 20:52:42 2006
@@ -55,7 +55,7 @@
     {
 	T elem( this->last() );
 	if ( !this->isEmpty() )
-	    remove( this->fromLast() );
+	   this->remove( this->fromLast() );
 	return elem;
     }
     T& top() { return this->last(); }
