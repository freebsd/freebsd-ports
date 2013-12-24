--- kodilib/src/tools/KXMLTools.cpp.orig	2003-04-14 01:42:13.000000000 +0400
+++ kodilib/src/tools/KXMLTools.cpp	2013-12-24 04:55:39.915558213 +0400
@@ -7,6 +7,7 @@
 #include "KConsole.h"
 #include "KSeparatedMatrix.h"
 #include <stdio.h>
+#include <cstdlib>
 
 // --------------------------------------------------------------------------------------------------------
 std::string kXMLTag ( const std::string & name, const std::string & attributes, int depth )
@@ -58,11 +59,11 @@
 std::string kXMLParseToTagsInVector ( std::string & xml, const std::vector<std::string> & tags )
 {
     std::string open("<");
-    unsigned int minLoc = std::string::npos; 
+    size_t minLoc = std::string::npos; 
     std::vector<std::string>::const_iterator iter = tags.begin();
     while (iter != tags.end())
     {
-        unsigned int loc = xml.find(open+(*iter));
+        size_t loc = xml.find(open+(*iter));
         if (loc < minLoc) minLoc = loc;
         iter++;
     }
@@ -77,7 +78,7 @@
     std::string value;
     std::string nameStr(name);
     nameStr += "='";
-    unsigned int loc = xml.find(nameStr);
+    size_t loc = xml.find(nameStr);
     if (loc != std::string::npos)
     {	
         loc += nameStr.size();
@@ -90,7 +91,7 @@
 // --------------------------------------------------------------------------------------------------------
 bool kXMLParseNamedCloseTag ( std::string & xml, const std::string & name, bool printError )
 {
-    unsigned int loc = xml.find('<');
+    size_t loc = xml.find('<');
     if (loc == std::string::npos) 
     {
         if (printError) KConsole::printError(kStringPrintf("invalid XML:\nmissing close tag '%s'", 
@@ -117,7 +118,7 @@
 // --------------------------------------------------------------------------------------------------------
 bool kXMLReadNamedOpenTag ( const std::string & xml, const std::string & name, std::string * attributes )
 {
-    unsigned int loc = xml.find('<'), endloc;
+    size_t loc = xml.find('<'), endloc;
     
     if (loc == std::string::npos || xml[loc+1] == '/') return false;
     
@@ -140,7 +141,7 @@
 // --------------------------------------------------------------------------------------------------------
 std::string kXMLParseNamedOpenTag ( std::string & xml, const std::string & name, std::string * attributes, bool printError )
 {
-    unsigned int loc = xml.find('<');
+    size_t loc = xml.find('<');
     if (loc == std::string::npos || xml[loc+1] == '/') 
     {
         if (printError) KConsole::printError(kStringPrintf("invalid XML:\nmissing tag '%s'", name.c_str()));
@@ -191,7 +192,7 @@
 // --------------------------------------------------------------------------------------------------------
 bool kXMLParseOpenTag ( std::string & xml, std::string & name, std::string * attributes, bool printError )
 {
-    unsigned int loc = xml.find('<');
+    size_t loc = xml.find('<');
     if (loc == std::string::npos || xml[loc+1] == '/') 
     {
         if (printError) KConsole::printError("invalid XML:\nmissing open tag");
@@ -295,7 +296,7 @@
 // --------------------------------------------------------------------------------------------------------
 bool kXMLParseValue( std::string & xml, const std::string & name, int type, void * value, bool printError )
 {
-    unsigned int loc = xml.find('<');
+    size_t loc = xml.find('<');
     if (loc == std::string::npos || xml[loc+1] == '/')     
     {
         if (printError) KConsole::printError(kStringPrintf("invalid XML:\nmissing value '%s'", name.c_str()));
@@ -379,8 +380,8 @@
         }
         else if (typeString == "string")
         {
-            unsigned int first = substring.find("\"")+1;
-            unsigned int last  = substring.rfind("\"", std::string::npos);
+            size_t first = substring.find("\"")+1;
+            size_t last  = substring.rfind("\"", std::string::npos);
             *((std::string*)value) = substring.substr(first, last-first);
         }
         
