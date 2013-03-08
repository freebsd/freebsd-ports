--- ./svtools/source/control/ctrlbox.cxx.orig	2013-01-31 05:54:53.000000000 -0500
+++ svtools/source/control/ctrlbox.cxx	2013-02-19 18:17:07.000000000 -0500
@@ -829,7 +829,7 @@
         if ( nPos < pLineList->size() ) {
             ImpLineList::iterator it = pLineList->begin();
             ::std::advance( it, nPos );
-            pLineList->insert( it, reinterpret_cast<ImpLineListData *>(NULL) );
+            pLineList->insert( it, static_cast<ImpLineListData *>(NULL) );
         } else {
             pLineList->push_back( NULL );
         }
