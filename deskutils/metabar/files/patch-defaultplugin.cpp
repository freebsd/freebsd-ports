--- src/defaultplugin.cpp.orig	Wed Jul 13 20:33:54 2005
+++ src/defaultplugin.cpp	Wed Jul 13 20:34:49 2005
@@ -99,7 +99,7 @@
   for(QStringList::Iterator it = actions.begin(); it != actions.end(); ++it){
     if((*it).startsWith("metabar/")){
       if((*it).right((*it).length() - 8) == "share"){
-        MetabarWidget::addEntry(innerHTML, i18n("Share"), "action://" + *it, "network", QString::null, actionCount < maxActions ? QString::null : "hiddenaction", actionCount >= maxActions);
+        MetabarWidget::addEntry(innerHTML, i18n("Share"), "action://" + *it, "network", QString::null, actionCount < maxActions ? QString::null : QString("hiddenaction"), actionCount >= maxActions);
         actionCount++;
       }
     }
@@ -111,7 +111,7 @@
           QString text = action.call("plainText()");
           QString icon = iconConfig.readEntry(*it, action.call("icon()"));
           
-          MetabarWidget::addEntry(innerHTML, text, "action://" + *it, icon, QString::null, actionCount < maxActions ? QString::null : "hiddenaction", actionCount >= maxActions);
+          MetabarWidget::addEntry(innerHTML, text, "action://" + *it, icon, QString::null, actionCount < maxActions ? QString::null : QString("hiddenaction"), actionCount >= maxActions);
           actionCount++;
         }
       }
@@ -184,7 +184,7 @@
             nam.setNum(id);
             
             bool hide = id >= max;
-            MetabarWidget::addEntry(innerHTML, (*it)->name(), "exec://" + nam, (*it)->icon(), QString::null, hide ? "hiddenapp" : QString::null, hide);
+            MetabarWidget::addEntry(innerHTML, (*it)->name(), "exec://" + nam, (*it)->icon(), QString::null, hide ? QString("hiddenapp") : QString::null, hide);
             
             runMap.insert(id, *it);
             id++;
