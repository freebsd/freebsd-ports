Fix crash when editing transactions
https://bugs.kde.org/show_bug.cgi?id=392735

--- kmymoney/widgets/qwidgetcontainer.cpp.orig	2018-03-18 15:55:30 UTC
+++ kmymoney/widgets/qwidgetcontainer.cpp
@@ -51,9 +51,10 @@ void QWidgetContainer::removeOrphans()
     if ((*it_w) && (*it_w)->parent())
       ++it_w;
     else {
-      delete(*it_w);
-      remove(it_w.key());
-      it_w = begin();
+      QWidget* const w = *it_w;
+      it_w = erase(it_w);
+      if (w)
+        w->deleteLater();
     }
   }
 }
