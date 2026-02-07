Build fails on FreeBSD due to urbackup's local definitions of isnumber()
conflicting with a library function. This patch renames the port's definition to
resolve the conflict. Analogous changes are also made in client/stringtools.h

--- client/stringtools.cpp.orig	2022-08-29 17:44:01 UTC
+++ client/stringtools.cpp
@@ -826,7 +826,7 @@ void TokenizeMail(const std::string& str, std::vector<
 //--------------------------------------------------------------------
 /**
 */
-bool isnumber(char ch)
+bool isnumber_local(char ch)
 {
 	if( ch>=48 && ch <=57 )
 		return true;
@@ -849,7 +849,7 @@ bool isletter(char ch)
 //--------------------------------------------------------------------
 /**
 */
-bool isnumber(wchar_t ch)
+bool isnumber_local(wchar_t ch)
 {
 	if( ch>=48 && ch <=57 )
 		return true;
@@ -929,7 +929,7 @@ int getNextNumber(const std::string &pStr, int *read)
 	bool start=false;
 	for(size_t i=0;i<pStr.size();++i)
 	{
-		if( isnumber(pStr[i] ) )
+		if( isnumber_local(pStr[i] ) )
 		{
 			num+=pStr[i];
 			start=true;
@@ -1444,7 +1444,7 @@ void replaceNonAlphaNumeric(std::string &str, char rch
 {
 	for(size_t i=0;i<str.size();++i)
 	{
-		if(isletter(str[i])==false && isnumber(str[i])==false)
+		if(isletter(str[i])==false && isnumber_local(str[i])==false)
 		{
 			str[i]=rch;
 		}
