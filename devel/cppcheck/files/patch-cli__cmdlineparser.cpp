--- ./cli/cmdlineparser.cpp.orig	2011-08-14 03:45:53.000000000 -0400
+++ ./cli/cmdlineparser.cpp	2011-09-17 03:13:23.000000000 -0400
@@ -535,7 +535,7 @@
             if (doc.LoadFile(12+argv[i]))
             {
                 TiXmlElement *node = doc.FirstChildElement();
-                for (; node && node->ValueStr() == "rule"; node = node->NextSiblingElement())
+                for (; node && node->Value() == "rule"; node = node->NextSiblingElement())
                 {
                     Settings::Rule rule;
 
