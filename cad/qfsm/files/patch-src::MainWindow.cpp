--- src/MainWindow.cpp.orig	Fri May  3 22:26:38 2002
+++ src/MainWindow.cpp	Sun Dec 22 07:46:43 2002
@@ -60,7 +60,7 @@
 #include "pics/editcopyoff.xpm"
 #include "pics/editpaste.xpm"
 #include "pics/editpasteoff.xpm"
-#include "pics/select.xpm"
+#include "pics/select1.xpm"
 #include "pics/selectoff.xpm"
 #include "pics/statenew.xpm"
 #include "pics/statenewoff.xpm"
@@ -418,7 +418,7 @@
  
   toolbar->addSeparator();
 
-  QPixmap pselect((const char**)select);
+  QPixmap pselect((const char**)select1);
   QPixmap pselectoff((const char**)selectoff);
   selset = new QIconSet(pselect);
   selset->setPixmap(pselectoff, QIconSet::Automatic, QIconSet::Disabled);
