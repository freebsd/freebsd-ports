--- src/sensors/rss.cpp.orig	2018-09-07 12:23:01 UTC
+++ src/sensors/rss.cpp
@@ -79,7 +79,7 @@ void RssSensor::update()
             if (!n.isNull()) {
                 QDomNodeList links = docElem.elementsByTagName("link");
                 QDomNodeList displays;
-                if (format.contains("%d", Qt::CaseInsensitive) > 0) {
+                if (format.contains("%d", Qt::CaseInsensitive)) {
                     displays = docElem.elementsByTagName("description");
                 } else {
                     displays = docElem.elementsByTagName("title");
