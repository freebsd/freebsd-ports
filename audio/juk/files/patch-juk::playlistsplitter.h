--- juk/playlistsplitter.h.orig	Mon Feb 17 06:23:26 2003
+++ juk/playlistsplitter.h	Mon Mar  3 12:24:34 2003
@@ -144,7 +144,7 @@
      */
     void open(const QString &file);
 
-    QStringList columnNames() const { return _columnNames; }
+    QStringList columnNames() const { return m_columnNames; }
     
     KActionMenu *columnVisibleAction() const { return collection->columnVisibleAction(); }
 
@@ -300,8 +300,8 @@
     QStringList directoryQueue;
     QStringList directoryQueueRemove;
 
-    QValueVector<bool> _visibleColumns;
-    QStringList _columnNames;
+    QValueVector<bool> m_visibleColumns;
+    QStringList m_columnNames;
 
     bool showEditor;
     bool restore;
