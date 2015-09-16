--- ./svtools/source/control/ctrlbox.cxx.orig	2013-03-12 07:00:34.000000000 -0400
+++ ./svtools/source/control/ctrlbox.cxx	2013-03-20 17:11:17.000000000 -0400
@@ -829,7 +829,7 @@
         if ( nPos < pLineList->size() ) {
             ImpLineList::iterator it = pLineList->begin();
             ::std::advance( it, nPos );
-            pLineList->insert( it, reinterpret_cast<ImpLineListData *>(NULL) );
+            pLineList->insert( it, static_cast<ImpLineListData *>(NULL) );
         } else {
             pLineList->push_back( NULL );
         }
