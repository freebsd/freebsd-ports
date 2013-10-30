--- src/imasm/parser.cpp.orig	2010-11-01 07:19:01.000000000 +0100
+++ src/imasm/parser.cpp	2013-10-29 06:17:34.000000000 +0100
@@ -65,7 +65,7 @@
 
 Parser::~Parser()
 {
-    map <const char *, macro *>::iterator itr;
+    map<const char *, macro *, Parser_ltstr>::iterator itr;
     
     for (itr = m_macroMap.begin(); itr != m_macroMap.end(); itr++)
     {
@@ -583,7 +583,7 @@
 
 macro *Parser::GetMacroPtr(const char *macName)
 {
-    map <const char *, macro *>::iterator itr;
+    map<const char *, macro *, Parser_ltstr>::iterator itr;
     
     itr = m_macroMap.find(macName);
     return itr == m_macroMap.end() ? NULL : itr->second;
