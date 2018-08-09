Build fails on FreeBSD due to urbackup's local definitions of isnumber() 
conflicting with a library function. This patch renames the port's definition to 
resolve the conflict. Analogous changes are also made in client/stringtools.cpp

--- client/stringtools.h.orig	2018-08-09 00:27:09.254786000 +0000
+++ client/stringtools.h	2018-08-09 00:27:23.137354000 +0000
@@ -69,9 +69,9 @@
 void Tokenize(std::string& str, std::vector<std::string> &tokens, std::string seps);
 void Tokenize(std::wstring& str, std::vector<std::wstring> &tokens, std::wstring seps);
 void TokenizeMail(std::string& str, std::vector<std::string> &tokens, std::string seps);
-bool isnumber(char ch);
+bool isnumber_local(char ch);
 bool isletter(char ch);
-bool isnumber(wchar_t ch);
+bool isnumber_local(wchar_t ch);
 bool isletter(wchar_t ch);
 void strupper(std::string *pStr);
 void strupper(std::wstring *pStr);
