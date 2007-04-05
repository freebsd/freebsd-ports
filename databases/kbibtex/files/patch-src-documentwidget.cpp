--- src/documentwidget.cpp.orig	Thu Apr  5 02:18:55 2007
+++ src/documentwidget.cpp	Thu Apr  5 02:18:11 2007
@@ -255,7 +255,11 @@
 
         updateFromGUI();
 
-        BibTeX::XSLTransform * transform = NULL;
+        KStandardDirs * kstd = KGlobal::dirs();
+        QString resPath = kstd->findResource( "data", "kbibtexpart/xslt/html.xsl" );
+        BibTeX::XSLTransform *transform = NULL;
+        if ( resPath != NULL )
+            transform = new BibTeX::XSLTransform( resPath );
 
         BibTeX::FileExporter * exporter = NULL;
         switch ( format )
@@ -471,13 +475,13 @@
         m_listViewElements->setFactory( factory, client );
         m_sourceView->setFactory( factory, client );
 
+        m_viewDocumentActionMenu = dynamic_cast<KActionMenu*>( client->action( "view_document" ) );
         if ( m_viewDocumentActionMenu != NULL )
             connect( m_viewDocumentActionMenu->popupMenu(), SIGNAL( activated( int ) ), this, SLOT( slotViewDocument( int ) ) );
 
         m_copyReference = client->action( "edit_copyref" );
         m_find = client->action( "edit_find" );
         m_findNext = client->action( "edit_find_next" );
-        m_viewDocumentActionMenu = dynamic_cast<KActionMenu*>( client->action( "view_document" ) );
         m_listViewElements->setViewShowColumnsMenu( dynamic_cast<KActionMenu*>( client->action( "view_showcolumns" ) ) );
         m_searchWebsitesActionMenu = dynamic_cast<KActionMenu*>( client->action( "search_document_online" ) );
     }
@@ -486,6 +490,7 @@
     {
         KPopupMenu * popup = m_viewDocumentActionMenu->popupMenu();
         popup->clear();
+        m_viewDocumentActionMenuURLs.clear();
 
         BibTeX::Element * currentElement = NULL;
 
@@ -517,6 +522,7 @@
                         popup->insertItem( SmallIcon( "html" ), prettyURL );
                     else
                         popup->insertItem( prettyURL );
+                    m_viewDocumentActionMenuURLs.append( prettyURL );
                 }
                 m_viewDocumentActionMenu->setEnabled( TRUE );
             }
@@ -908,7 +914,7 @@
 
     void DocumentWidget::slotViewDocument( int id )
     {
-        kapp->invokeBrowser( m_viewDocumentActionMenu->popupMenu() ->text( id ) );
+        kapp->invokeBrowser( m_viewDocumentActionMenuURLs[ m_viewDocumentActionMenu->popupMenu() ->indexOf( id ) ] );
     }
 
 }
