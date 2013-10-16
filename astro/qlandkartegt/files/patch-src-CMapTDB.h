--- src/CMapTDB.h.orig	2013-08-15 19:13:38.000000000 +0400
+++ src/CMapTDB.h	2013-09-25 08:45:54.954519968 +0400
@@ -209,7 +209,7 @@
             quint8 level;
             bool useBaseMap;
 
-            bool operator==(const map_level_t &ml)
+            bool operator==(const map_level_t &ml) const
             {
                 if (ml.bits != bits || ml.level != level || ml.useBaseMap != useBaseMap)
                     return false;
