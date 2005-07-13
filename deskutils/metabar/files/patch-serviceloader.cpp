--- src/serviceloader.cpp.orig	Wed Jul 13 20:31:36 2005
+++ src/serviceloader.cpp	Wed Jul 13 20:32:30 2005
@@ -154,7 +154,7 @@
               popup = popups[submenuName];
             }
             else{              
-              MetabarWidget::addEntry(html, submenuName, "servicepopup://" + idString, "1rightarrow", "popup" + idString, count < maxActions ? QString::null : "hiddenaction", count >= maxActions);
+              MetabarWidget::addEntry(html, submenuName, "servicepopup://" + idString, "1rightarrow", "popup" + idString, count < maxActions ? QString::null : QString("hiddenaction"), count >= maxActions);
               
               popup = new KPopupMenu();
               popups.insert(idString, popup);
@@ -172,7 +172,7 @@
               action->plug(popup);
             }
             else{
-              MetabarWidget::addEntry(html, (*it).m_strName, "service://" + idString, (*it).m_strIcon, QString::null, count < maxActions ? QString::null : "hiddenaction", count >= maxActions);
+              MetabarWidget::addEntry(html, (*it).m_strName, "service://" + idString, (*it).m_strIcon, QString::null, count < maxActions ? QString::null : QString("hiddenaction"), count >= maxActions);
               count++;
             }
             
