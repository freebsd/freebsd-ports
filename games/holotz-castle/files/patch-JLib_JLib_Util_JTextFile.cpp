--- JLib/JLib/Util/JTextFile.cpp.orig	2009-05-02 09:17:15 UTC
+++ JLib/JLib/Util/JTextFile.cpp
@@ -145,7 +145,7 @@ bool JTextFile::FindNext(const s8 *str, 
   
   tmp = strstr(ptr, str);
 
-  if (tmp > 0)
+  if (tmp)
     ptr = tmp;
   else
   {
@@ -153,7 +153,7 @@ bool JTextFile::FindNext(const s8 *str, 
     {
       tmp = strstr(buff, str);
 
-      if (tmp > 0)
+      if (tmp)
         ptr = tmp;
       else
         return false;
@@ -233,7 +233,7 @@ bool JTextFile::ReadQuotedWord(s8 *str)
 	++ptr;
 	end = ptr;
 	
-	if (0 >= (end = strstr(ptr, "\"")))
+	if ((end = strstr(ptr, "\"")))
 	{
 		// No hay comillas de cierre
 		ptr = org;
