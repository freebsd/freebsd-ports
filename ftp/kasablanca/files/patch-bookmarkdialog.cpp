--- src/bookmarkdialog.cpp.orig	Fri Apr 16 11:59:56 2004
+++ src/bookmarkdialog.cpp	Fri Apr 16 12:03:43 2004
@@ -43,7 +43,7 @@
 	{
 		EnableInput(true);
 		BookmarkListBox->setSelected(0, true);
-		RefreshEntry(m_bookmarks.at(0));
+		RefreshEntry(m_bookmarks[0]);
 	}
 }
 
@@ -110,7 +110,7 @@
 
 	for (int i = 0; i < static_cast<int>(m_bookmarks.size()); i++)
    {
-		BookmarkListBox->insertItem(m_bookmarks.at(i).GetName(),i);
+		BookmarkListBox->insertItem(m_bookmarks[i].GetName(),i);
    }
 
 	return 1;
@@ -131,7 +131,7 @@
 		return;
 	}
 
-	if (ApplyEntry(&m_bookmarks.at(n)))
+	if (ApplyEntry(&m_bookmarks[n]))
 	{
 		if (WriteBookmarks() != 1)
 		{
@@ -145,7 +145,7 @@
 
 void BookmarkDialog::SLOT_EntrySelected(int n)
 {
-	RefreshEntry(m_bookmarks.at(n));
+	RefreshEntry(m_bookmarks[n]);
 }
 
 void BookmarkDialog::SLOT_ApplyEntry()
@@ -154,13 +154,13 @@
 
 	int n = BookmarkListBox->currentItem();
 
-	if (!ApplyEntry(&m_bookmarks.at(n))) KMessageBox::error(0,"entry form not complete!");
+	if (!ApplyEntry(&m_bookmarks[n])) KMessageBox::error(0,"entry form not complete!");
 	else
 	{
 		BookmarkListBox->clear();
 		for (int i = 0; i < static_cast<int>(m_bookmarks.size()); i++)
    	{
-			BookmarkListBox->insertItem(m_bookmarks.at(i).GetName(),i);
+			BookmarkListBox->insertItem(m_bookmarks[i].GetName(),i);
    	}
 		BookmarkListBox->setSelected(n, true);
 	}
@@ -198,7 +198,7 @@
 	BookmarkListBox->clear();
 	for (int i = 0; i < static_cast<int>(m_bookmarks.size()); i++)
    {
-		BookmarkListBox->insertItem(m_bookmarks.at(i).GetName(),i);
+		BookmarkListBox->insertItem(m_bookmarks[i].GetName(),i);
    }
 
 	if (m_bookmarks.empty()) EnableInput(false);
@@ -206,7 +206,7 @@
 	{
 		EnableInput(true);
 		BookmarkListBox->setSelected(0, true);
-		RefreshEntry(m_bookmarks.at(0));
+		RefreshEntry(m_bookmarks[0]);
 	}
 }
 
@@ -218,10 +218,10 @@
 
 	for (int i = 0; i < static_cast<int>(m_bookmarks.size()); i++)
 	{
-		if (m_bookmarks.at(i).CheckContent())
+		if (m_bookmarks[i].CheckContent())
 		{
 			QDomElement siteElement = doc.createElement("site");
-			siteElement.setAttribute("name", m_bookmarks.at(i).GetName());
+			siteElement.setAttribute("name", m_bookmarks[i].GetName());
 			root.appendChild( siteElement );
 
 			QDomText text;
@@ -229,27 +229,27 @@
 
 			curElement = doc.createElement( "user" );
 			siteElement.appendChild( curElement );
-			text = doc.createTextNode(m_bookmarks.at(i).GetUser());
+			text = doc.createTextNode(m_bookmarks[i].GetUser());
 			curElement.appendChild(text);
 
 			curElement = doc.createElement( "pass" );
 			siteElement.appendChild( curElement );
-			text = doc.createTextNode(m_bookmarks.at(i).GetPass());
+			text = doc.createTextNode(m_bookmarks[i].GetPass());
 			curElement.appendChild(text);
 
 			curElement = doc.createElement( "info" );
 			siteElement.appendChild( curElement );
-			text = doc.createTextNode(m_bookmarks.at(i).GetInfo());
+			text = doc.createTextNode(m_bookmarks[i].GetInfo());
 			curElement.appendChild(text);
 
 			curElement = doc.createElement( "pasv" );
 			siteElement.appendChild( curElement );
-			text = doc.createTextNode(QString::number(m_bookmarks.at(i).GetPasv()));
+			text = doc.createTextNode(QString::number(m_bookmarks[i].GetPasv()));
 			curElement.appendChild(text);
 
 			curElement = doc.createElement( "tls" );
 			siteElement.appendChild( curElement );
-			text = doc.createTextNode(QString::number(m_bookmarks.at(i).GetTls()));
+			text = doc.createTextNode(QString::number(m_bookmarks[i].GetTls()));
 			curElement.appendChild(text);
 		}
 	}
