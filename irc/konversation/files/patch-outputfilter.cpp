--- konversation/konversation/outputfilter.cpp.orig	Mon Jul  5 00:37:19 2004
+++ konversation/konversation/outputfilter.cpp	Mon Jul  5 00:37:43 2004
@@ -1081,7 +1081,7 @@
             break;
           }
         }
-        if (validGroup and splitted.count() > 1)
+        if (validGroup && splitted.count() > 1)
         {
           QString option = splitted[1];
           QMap<QString,QString> options = config->entryMap(group);
