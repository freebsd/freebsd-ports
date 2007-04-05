Index: src/documentwidget.h
===================================================================
--- src/documentwidget.h	(Revision 308)
+++ src/documentwidget.h	(Revision 310)
@@ -106,6 +106,7 @@
         int m_newElementCounter;
         EditMode m_editMode;
         KActionMenu *m_viewDocumentActionMenu;
+        QStringList m_viewDocumentActionMenuURLs;
         KActionMenu *m_searchWebsitesActionMenu;
         KAction *m_find;
         KAction *m_findNext;
