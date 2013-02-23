--- ../orig/HLLib/Error.cpp	2010-04-17 13:48:52.000000000 -0300
+++ ./HLLib/Error.cpp	2013-02-11 18:00:09.931600402 -0200
@@ -139,7 +139,7 @@
 
 		hlUInt uiLength = (hlUInt)strlen(this->lpSystemError);
 
-		while(uiLength >= 0 && isspace(this->lpSystemError[uiLength - 1]))
+		while(isspace(this->lpSystemError[uiLength - 1]))
 		{
 			uiLength--;
 		}
diff -ru ../orig/HLLib/FileStream.cpp ./HLLib/FileStream.cpp
