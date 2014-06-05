--- utils/idftools/idf_parser.cpp.orig	2014-06-05 12:18:16.912481412 +0000
+++ utils/idftools/idf_parser.cpp	2014-06-05 12:19:15.292871266 +0000
@@ -1489,6 +1489,6 @@
     do
     {
-        std::map<std::string, GROUP_OUTLINE*>::iterator its = olnGroup.begin();
-        std::map<std::string, GROUP_OUTLINE*>::iterator ite = olnGroup.end();
+        std::multimap<std::string, GROUP_OUTLINE*>::iterator its = olnGroup.begin();
+        std::multimap<std::string, GROUP_OUTLINE*>::iterator ite = olnGroup.end();
 
         while( its != ite )
@@ -2906,6 +2906,6 @@
         do
         {
-            std::map<std::string, GROUP_OUTLINE*>::iterator its = olnGroup.begin();
-            std::map<std::string, GROUP_OUTLINE*>::iterator ite = olnGroup.end();
+            std::multimap<std::string, GROUP_OUTLINE*>::iterator its = olnGroup.begin();
+            std::multimap<std::string, GROUP_OUTLINE*>::iterator ite = olnGroup.end();
 
             while( its != ite )
@@ -4103,6 +4103,6 @@
     do
     {
-        std::map<std::string, GROUP_OUTLINE*>::iterator os = olnGroup.begin();
-        std::map<std::string, GROUP_OUTLINE*>::iterator oe = olnGroup.end();
+        std::multimap<std::string, GROUP_OUTLINE*>::iterator os = olnGroup.begin();
+        std::multimap<std::string, GROUP_OUTLINE*>::iterator oe = olnGroup.end();
 
         while( os != oe )
