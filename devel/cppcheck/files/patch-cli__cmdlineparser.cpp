--- cli/cmdlineparser.cpp.orig	2011-12-10 07:00:45.000000000 -0500
+++ cli/cmdlineparser.cpp	2011-12-10 22:32:04.000000000 -0500
@@ -557,7 +557,7 @@
             TiXmlDocument doc;
             if (doc.LoadFile(12+argv[i])) {
                 TiXmlElement *node = doc.FirstChildElement();
-                for (; node && node->ValueStr() == "rule"; node = node->NextSiblingElement()) {
+                for (; node && node->Value() == "rule"; node = node->NextSiblingElement()) {
                     Settings::Rule rule;
 
                     TiXmlElement *pattern = node->FirstChildElement("pattern");
