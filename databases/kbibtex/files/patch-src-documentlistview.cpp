Index: src/documentlistview.cpp
===================================================================
--- src/documentlistview.cpp	(Revision 301)
+++ src/documentlistview.cpp	(Revision 302)
@@ -221,10 +221,13 @@
         while ( it.current() )
         {
             DocumentListViewItem * kblvi = dynamic_cast<DocumentListViewItem*>( it.current() );
-            m_bibtexFile->deleteElement( kblvi->element() );
-            it++;
-            takeItem( kblvi );
-            delete ( kblvi );
+            if ( kblvi->isVisible() )
+            {
+                m_bibtexFile->deleteElement( kblvi->element() );
+                it++;
+                takeItem( kblvi );
+                delete ( kblvi );
+            }
         }
 
         if ( above )
@@ -246,7 +249,7 @@
         {
             DocumentListViewItem * kblvi = dynamic_cast<DocumentListViewItem*>( it.current() );
             BibTeX::Entry *entry = dynamic_cast<BibTeX::Entry*>( kblvi->element() );
-            if ( entry != NULL )
+            if ( entry != NULL && kblvi->isVisible() )
             {
                 if ( !refs.isEmpty() )
                     refs.append( "," );
@@ -621,7 +624,8 @@
         while ( it.current() )
         {
             DocumentListViewItem * kblvi = dynamic_cast<DocumentListViewItem*>( it.current() );
-            exporter->save( &buffer, kblvi->element() );
+            if ( kblvi->isVisible() )
+                exporter->save( &buffer, kblvi->element() );
             it++;
         }
         delete exporter;
