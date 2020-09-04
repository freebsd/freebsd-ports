--- src/imasm/parser.cpp.orig	2010-11-01 06:19:01 UTC
+++ src/imasm/parser.cpp
@@ -65,7 +65,7 @@ int stricmp_(const char *str1, const char *str2)
 
 Parser::~Parser()
 {
-    map <const char *, macro *>::iterator itr;
+    map<const char *, macro *, Parser_ltstr>::iterator itr;
     
     for (itr = m_macroMap.begin(); itr != m_macroMap.end(); itr++)
     {
@@ -583,7 +583,7 @@ int Parser::FindMacros(string &sLine, string &sOut)
 
 macro *Parser::GetMacroPtr(const char *macName)
 {
-    map <const char *, macro *>::iterator itr;
+    map<const char *, macro *, Parser_ltstr>::iterator itr;
     
     itr = m_macroMap.find(macName);
     return itr == m_macroMap.end() ? NULL : itr->second;
