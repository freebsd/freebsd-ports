--- uds/alloc.cc.orig	Thu Sep  5 10:07:25 2002
+++ uds/alloc.cc	Thu Sep  5 10:08:48 2002
@@ -27,26 +27,26 @@
 
 
 void*
-operator new ( size_t size )
+operator new ( size_t size ) throw ( std::bad_alloc )
 {
 	return uds::sentinel().Allocate( size );
 }
 
 void*
-operator new [] ( size_t size )
+operator new [] ( size_t size ) throw ( std::bad_alloc )
 {
 	return uds::sentinel().Allocate( size );
 }
 
 void
-operator delete ( void* p )
+operator delete ( void* p ) throw ()
 {
 	if ( p )
 		uds::sentinel().Release( p );
 }
 
 void
-operator delete [] ( void* p )
+operator delete [] ( void* p ) throw ()
 {
 	if ( p )
 		uds::sentinel().Release( p );
