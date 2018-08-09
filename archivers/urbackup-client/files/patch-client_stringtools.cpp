Build fails on FreeBSD due to urbackup's local definitions of isnumber()
conflicting with a library function. This patch renames the port's definition to
resolve the conflict. Analogous changes are also made in client/stringtools.h

--- client/stringtools.cpp.orig	2018-08-09 00:15:57.062820000 +0000
+++ client/stringtools.cpp	2018-08-09 00:16:38.573398000 +0000
@@ -825,7 +825,7 @@
 //--------------------------------------------------------------------
 /**
 */
-bool isnumber(char ch)
+bool isnumber_local(char ch)
 {
 	if( ch>=48 && ch <=57 )
 		return true;
@@ -848,7 +848,7 @@
 //--------------------------------------------------------------------
 /**
 */
-bool isnumber(wchar_t ch)
+bool isnumber_local(wchar_t ch)
 {
 	if( ch>=48 && ch <=57 )
 		return true;
@@ -928,7 +928,7 @@
 	bool start=false;
 	for(size_t i=0;i<pStr.size();++i)
 	{
-		if( isnumber(pStr[i] ) )
+		if( isnumber_local(pStr[i] ) )
 		{
 			num+=pStr[i];
 			start=true;
@@ -1445,7 +1445,7 @@
 {
 	for(size_t i=0;i<str.size();++i)
 	{
-		if(isletter(str[i])==false && isnumber(str[i])==false)
+		if(isletter(str[i])==false && isnumber_local(str[i])==false)
 		{
 			str[i]=rch;
 		}
@@ -1497,4 +1497,4 @@
 		}
 	}
 	return ret;
-}
\ No newline at end of file
+}
