--- app/settings/delegates/persistentmenu.cpp.orig	2019-08-28 20:32:23 UTC
+++ app/settings/delegates/persistentmenu.cpp
@@ -20,7 +20,7 @@
 #include "persistentmenu.h"
 
 
-PersistentMenu::PersistentMenu(QWidget *parent = 0)
+PersistentMenu::PersistentMenu(QWidget *parent)
     : QMenu (parent),
       m_blockHide(false)
 {
