--- ./src/WptIcons.cpp.orig	2011-02-16 22:32:47.000000000 +0200
+++ ./src/WptIcons.cpp	2011-02-26 17:27:33.000000000 +0200
@@ -102,15 +102,15 @@
     setWptIconByName("Custom 23", cfg.value("garmin/icons/custom23", ":/icons/wpt/custom15x15.bmp").toString());
     setWptIconByName("Custom 24", cfg.value("garmin/icons/custom24", ":/icons/wpt/custom15x15.bmp").toString());
 
-    setWptIconByName("Traditional Cache", ":/icons/cache/Traditional Cache.png");
+    setWptIconByName("Traditional Cache", ":/icons/cache/Traditional-Cache.png");
     setWptIconByName("Multi-cache", ":/icons/cache/Multi-cache.png");
-    setWptIconByName("Unknown Cache", ":/icons/cache/Unknown Cache.png");
-    setWptIconByName("Wherigo Cache", ":/icons/cache/Wherigo Cache.png");
-    setWptIconByName("Event Cache", ":/icons/cache/Event Cache.png");
+    setWptIconByName("Unknown Cache", ":/icons/cache/Unknown-Cache.png");
+    setWptIconByName("Wherigo Cache", ":/icons/cache/Wherigo-Cache.png");
+    setWptIconByName("Event Cache", ":/icons/cache/Event-Cache.png");
     setWptIconByName("Earthcache", ":/icons/cache/Earthcache.png");
-    setWptIconByName("Letterbox Hybrid", ":/icons/cache/Letterbox Hybrid.png");
-    setWptIconByName("Virtual Cache", ":/icons/cache/Virtual Cache.png");
-    setWptIconByName("Webcam Cache", ":/icons/cache/Webcam Cache.png");
+    setWptIconByName("Letterbox Hybrid", ":/icons/cache/Letterbox-Hybrid.png");
+    setWptIconByName("Virtual Cache", ":/icons/cache/Virtual-Cache.png");
+    setWptIconByName("Webcam Cache", ":/icons/cache/Webcam-Cache.png");
 
     QDir dirIcon(QDir::home().filePath(CONFIGDIR));
     dirIcon.mkdir("WaypointIcons");
