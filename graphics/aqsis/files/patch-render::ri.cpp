--- render/ri.cpp.orig	Mon Apr 12 13:49:57 2004
+++ render/ri.cpp	Mon Apr 12 13:51:26 2004
@@ -3608,7 +3608,7 @@
                 TqInt iElem;
                 for( iElem = 0; iElem < fvcount; ++iElem )
                 {
-                    const unsigned char* pval = static_cast<const unsigned char*>( values[ iUserParam ] ) + ( aFVList[ iElem ] * elem_size );
+                    unsigned char* pval = static_cast<unsigned char*>( values[ iUserParam ] ) + ( aFVList[ iElem ] * elem_size );
                     memcpy( pNew, pval, elem_size );
                     pNew += elem_size;
                 }
