--- src/kasablanca.cpp.orig	Fri Apr 16 11:52:53 2004
+++ src/kasablanca.cpp	Fri Apr 16 11:58:46 2004
@@ -465,12 +465,12 @@
 			
 	site->Clear();
 
-	site->SetInfo(m_bookmarks.at(n).GetInfo());
-	site->SetName(m_bookmarks.at(n).GetName());
-	site->SetPass(m_bookmarks.at(n).GetPass());
-	site->SetPasv(m_bookmarks.at(n).GetPasv());
-	site->SetTls(m_bookmarks.at(n).GetTls());
-	site->SetUser(m_bookmarks.at(n).GetUser());
+	site->SetInfo(m_bookmarks[n].GetInfo());
+	site->SetName(m_bookmarks[n].GetName());
+	site->SetPass(m_bookmarks[n].GetPass());
+	site->SetPasv(m_bookmarks[n].GetPasv());
+	site->SetTls(m_bookmarks[n].GetTls());
+	site->SetUser(m_bookmarks[n].GetUser());
 
 	if (!proc->start())
 	{
@@ -678,8 +678,8 @@
 	
 	for (int i = 0; i < static_cast<int>(m_bookmarks.size()); i++)
    {
-		m_bookmarksmenu_a.insertItem(m_bookmarks.at(i).GetName(),i + 1);
-   	m_bookmarksmenu_b.insertItem(m_bookmarks.at(i).GetName(),i + 1);
+		m_bookmarksmenu_a.insertItem(m_bookmarks[i].GetName(),i + 1);
+   	m_bookmarksmenu_b.insertItem(m_bookmarks[i].GetName(),i + 1);
    }
 
    return 1;
@@ -1370,7 +1370,7 @@
 			UpdateLocalDisplay(localbrowser);
 			UpdateRemote(remotebrowser);
 		}
-		else if ((dir->type() == transferitem::fxp_a_to_b) or (dir->type() == transferitem::fxp_b_to_a))
+		else if ((dir->type() == transferitem::fxp_a_to_b) || (dir->type() == transferitem::fxp_b_to_a))
 		{
 			/* the scan dir flag is set */
 
@@ -1556,7 +1556,7 @@
 				dialog.OverwriteButton->setEnabled(false);
 			}
 
-			if ((file->m_filocal.isFile() == true) or (file->m_filocal.isDir() == true))
+			if ((file->m_filocal.isFile() == true) || (file->m_filocal.isDir() == true))
 			{
 				filepresent = true;
 				dialog.setCaption(file->m_filocal.fileName() + " exists yet...");
@@ -1574,7 +1574,7 @@
 				case 4:
 					bool b = false;
 					
-					while ((filepresent) or (!b))
+					while ((filepresent) || (!b))
 					//while ((localname.lower() == file->m_firemote.fileName().lower()) || (!b))
 					{
 						#if KDE_IS_VERSION(3,2,0)
@@ -1585,7 +1585,7 @@
 
 						filepresent = false;
 						QFileInfo fi(file->m_filocal.dirPath() + "/" + localname);
-						if ((fi.isFile() == true) or (fi.isDir() == true)) filepresent = true;
+						if ((fi.isFile() == true) || (fi.isDir() == true)) filepresent = true;
 					}
 					break;
 				}
@@ -1930,10 +1930,10 @@
 	{
 		diritem * di = new diritem(browser,
 			browser->lastItem(),
-			ditable.at(i).fileName(),
-			ditable.at(i).dirPath(),
-			ditable.at(i).date(),
-			ditable.at(i).size(),ditable.at(i).date_int());
+			ditable[i].fileName(),
+			ditable[i].dirPath(),
+			ditable[i].date(),
+			ditable[i].size(),ditable[i].date_int());
 		di->setPixmap(0, il->loadIcon("folder",KIcon::Small));
 	}
 
@@ -1941,11 +1941,11 @@
 	{
 		fileitem * fi = new fileitem(browser,
 			browser->lastItem(),
-			fitable.at(i).fileName(),
-			fitable.at(i).dirPath(),
-			fitable.at(i).date(),
-			fitable.at(i).size(),
-			fitable.at(i).date_int());
+			fitable[i].fileName(),
+			fitable[i].dirPath(),
+			fitable[i].date(),
+			fitable[i].size(),
+			fitable[i].date_int());
 		fi->setPixmap(0, il->loadIcon("files",KIcon::Small));
 	}
 
