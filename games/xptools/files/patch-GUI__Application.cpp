--- src/GUI/GUI_Application.cpp.orig	2018-07-05 06:04:16 UTC
+++ src/GUI/GUI_Application.cpp
@@ -114,7 +114,7 @@ void GUI_QtMenu::showEvent( QShowEvent *
 {
     QList<QAction*> actlist = this->actions();
     QList<QAction*>::iterator it = actlist.begin();
-    for (it ; it != actlist.end(); ++it)
+    for (it = actlist.begin(); it != actlist.end(); ++it)
     {
         int cmd = (*it)->data().toInt();
         if (cmd)
@@ -136,7 +136,7 @@ void GUI_QtMenu::hideEvent( QHideEvent *
     // items and their shortcut-action while showevent .
     QList<QAction*> actlist = this->actions();
     QList<QAction*>::iterator it = actlist.begin();
-    for (it ; it != actlist.end(); ++it)
+    for (it  = actlist.begin() ; it != actlist.end(); ++it)
     {
         int cmd = (*it)->data().toInt();
         if (cmd)  (*it)->setEnabled(true);
