--- src/zipios_common.h.orig	Fri Aug  4 09:26:00 2000
+++ src/zipios_common.h	Sat Sep  7 10:46:20 2002
@@ -13,7 +13,7 @@
 
 template< class Type >
 void operator += ( vector< Type > &v1, const vector< Type > &v2 ) {
-  std::vector<Type>::const_iterator cit ;
+  typename std::vector<Type>::const_iterator cit ;
   for ( cit = v2.begin() ; cit != v2.end() ; cit++ )
     v1.push_back( *cit ) ;
 }
