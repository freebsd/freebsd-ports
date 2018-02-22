--- shell/shell.cpp
+++ shell/shell.cpp
@@ -163,7 +163,7 @@ bool Shell::openDocument( const QString& url, const QString &serializedOptions )
     KParts::ReadWritePart* const part = m_tabs[0].part;
 
     // Return false if we can't open new tabs and the only part is occupied
-    if ( !dynamic_cast<Okular::ViewerInterface*>(part)->openNewFilesInTabs()
+    if ( !qobject_cast<Okular::ViewerInterface*>(part)->openNewFilesInTabs()
          && !part->url().isEmpty()
          && !ShellUtils::unique(serializedOptions))
     {
@@ -181,7 +181,7 @@ bool Shell::canOpenDocs( int numDocs, int desktop )
       return false;
 
    KParts::ReadWritePart* const part = m_tabs[0].part;
-   const bool allowTabs = dynamic_cast<Okular::ViewerInterface*>(part)->openNewFilesInTabs();
+   const bool allowTabs = qobject_cast<Okular::ViewerInterface*>(part)->openNewFilesInTabs();
 
    if( !allowTabs && (numDocs > 1 || !part->url().isEmpty()) )
       return false;
@@ -208,7 +208,7 @@ void Shell::openUrl( const KUrl & url, const QString &serializedOptions )
             }
             else
             {
-                if( dynamic_cast<Okular::ViewerInterface *>(activePart)->openNewFilesInTabs() )
+                if( qobject_cast<Okular::ViewerInterface *>(activePart)->openNewFilesInTabs() )
                 {
                     openNewTab( url, serializedOptions );
                 }
