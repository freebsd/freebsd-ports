--- render/ri.cpp.orig	Fri Sep 19 17:03:14 2003
+++ render/ri.cpp	Mon Sep 29 11:33:21 2003
@@ -3271,7 +3271,7 @@
 				TqInt iElem;
 				for( iElem = 0; iElem < fvcount; iElem++ )
 				{
-					const unsigned char* pval = static_cast<const unsigned char*>( values[ iUserParam ] ) + ( aFVList[ iElem ] * elem_size );
+					unsigned char* pval = static_cast<unsigned char*>( values[ iUserParam ] ) + ( aFVList[ iElem ] * elem_size );
 					memcpy( pNew, pval, elem_size );
 					pNew += elem_size;
 				}
