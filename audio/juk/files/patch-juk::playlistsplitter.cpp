--- juk/playlistsplitter.cpp.orig	Mon Feb 17 09:46:30 2003
+++ juk/playlistsplitter.cpp	Mon Mar  3 12:24:34 2003
@@ -443,7 +443,7 @@
 
 		    // check to see if we've alredy loaded this item before continuing
 
-		    if(!playlistFiles.insert(p->fileName()))
+		    if(p->fileName().isEmpty() || !playlistFiles.insert(p->fileName()))
 			setupPlaylist(p);
 		    else
 			delete p;
@@ -458,19 +458,19 @@
 
 	if(collection) {
 	    // the last column is just a filler
-	    _visibleColumns.resize(collection->columns() - 1, true);
+	    m_visibleColumns.resize(collection->columns() - 1, true);
 	    QValueList<int> l = config->readIntListEntry("VisibleColumns");
 
 	    uint i = 0;
 	    for(QValueList<int>::Iterator it = l.begin(); it != l.end(); ++it) {
 		if(! bool(*it)) {
-		    _visibleColumns[i] = bool(*it);
+		    m_visibleColumns[i] = bool(*it);
 		    collection->hideColumn(i);
 		}
 
-		// while we're looping go ahead and populate _columnNames
+		// while we're looping go ahead and populate m_columnNames
 		
-		_columnNames.append(collection->columnText(i));
+		m_columnNames.append(collection->columnText(i));
 
 		i++;
 	    }
@@ -513,8 +513,8 @@
 	    config->writeEntry("DirectoryList", directoryList);
 
 	    QValueList<int> l;
-	    for(uint i = 0; i < _visibleColumns.size(); i++)
-		l.append(int(_visibleColumns[i]));
+	    for(uint i = 0; i < m_visibleColumns.size(); i++)
+		l.append(int(m_visibleColumns[i]));
 	    
 	    config->writeEntry("VisibleColumns", l);
 
@@ -583,10 +583,10 @@
     if(!p)
 	return;
     
-    for(uint i = 0; i < _visibleColumns.size(); i++) {
-	if(_visibleColumns[i] && ! p->isColumnVisible(i))
+    for(uint i = 0; i < m_visibleColumns.size(); i++) {
+	if(m_visibleColumns[i] && ! p->isColumnVisible(i))
 	    p->showColumn(i);
-	else if(! _visibleColumns[i] && p->isColumnVisible(i))
+	else if(! m_visibleColumns[i] && p->isColumnVisible(i))
 	    p->hideColumn(i);
     }
 }
@@ -619,7 +619,7 @@
 
 void PlaylistSplitter::slotToggleColumnVisible(int column)
 {
-    _visibleColumns[column] = ! _visibleColumns[column];
+    m_visibleColumns[column] = ! m_visibleColumns[column];
     if(visiblePlaylist())
 	setupColumns(visiblePlaylist());
 }
