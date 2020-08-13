--- shell/shell.cpp.orig	2020-07-18 10:42:15 UTC
+++ shell/shell.cpp
@@ -215,7 +215,7 @@ bool Shell::openDocument(const QUrl &url, const QStrin
     KParts::ReadWritePart *const part = m_tabs[0].part;
 
     // Return false if we can't open new tabs and the only part is occupied
-    if (!dynamic_cast<Okular::ViewerInterface *>(part)->openNewFilesInTabs() && !part->url().isEmpty() && !ShellUtils::unique(serializedOptions)) {
+    if (!qobject_cast<Okular::ViewerInterface *>(part)->openNewFilesInTabs() && !part->url().isEmpty() && !ShellUtils::unique(serializedOptions)) {
         return false;
     }
 
@@ -235,7 +235,7 @@ bool Shell::canOpenDocs(int numDocs, int desktop)
         return false;
 
     KParts::ReadWritePart *const part = m_tabs[0].part;
-    const bool allowTabs = dynamic_cast<Okular::ViewerInterface *>(part)->openNewFilesInTabs();
+    const bool allowTabs = qobject_cast<Okular::ViewerInterface *>(part)->openNewFilesInTabs();
 
     if (!allowTabs && (numDocs > 1 || !part->url().isEmpty()))
         return false;
@@ -257,7 +257,7 @@ void Shell::openUrl(const QUrl &url, const QString &se
                 applyOptionsToPart(activePart, serializedOptions);
                 activePart->openUrl(url);
             } else {
-                if (dynamic_cast<Okular::ViewerInterface *>(activePart)->openNewFilesInTabs()) {
+                if (qobject_cast<Okular::ViewerInterface *>(activePart)->openNewFilesInTabs()) {
                     openNewTab(url, serializedOptions);
                 } else {
                     Shell *newShell = new Shell(serializedOptions);
