--- juk/playlist.cpp.orig	Mon Feb 17 09:50:48 2003
+++ juk/playlist.cpp	Mon Mar  3 12:24:34 2003
@@ -215,7 +215,7 @@
 		    delete it.current();
 		}
 		else
-		    KMessageBox::sorry(this, i18n("Could not save delete ") + it.current()->fileName() + ".");
+		    KMessageBox::sorry(this, i18n("Could not delete ") + it.current()->fileName() + ".");
 	    }
 
 	}
@@ -483,7 +483,7 @@
 
     _columnVisibleAction = new KActionMenu(i18n("Show Columns"), this, "showColumns");
     headerMenu = _columnVisibleAction->popupMenu();
-    headerMenu->insertTitle(i18n("Show..."));
+    headerMenu->insertTitle(i18n("Show"));
     headerMenu->setCheckable(true);
 
     for(int i =0; i < header()->count(); ++i) {
@@ -508,7 +508,7 @@
 
     rmbMenu->insertSeparator();
 
-    rmbMenu->insertItem(SmallIcon("editdelete"), i18n("Remove from disk"), this, SLOT(removeSelectedItems()));
+    rmbMenu->insertItem(SmallIcon("editdelete"), i18n("Remove From Disk"), this, SLOT(removeSelectedItems()));
 
     rmbMenu->insertSeparator();
 
