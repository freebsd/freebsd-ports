--- src/gis/CGisListWks.cpp.orig	2016-09-19 19:38:41.441780000 +0200
+++ src/gis/CGisListWks.cpp	2016-09-19 19:38:56.183055000 +0200
@@ -346,7 +346,7 @@
     QAction * action = menu->addAction(QIcon(icon), text);
     action->setCheckable(true);
 
-    auto func = bind(&CGisListWks::slotSetSortMode, this, mode, std::placeholders::_1);
+    auto func = std::bind(&CGisListWks::slotSetSortMode, this, mode, std::placeholders::_1);
     connect(action, &QAction::toggled, this, func);
 
     actionGroup->addAction(action);
