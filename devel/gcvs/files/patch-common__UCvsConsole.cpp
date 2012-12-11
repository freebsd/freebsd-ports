--- common/UCvsConsole.cpp.orig	2000-06-06 14:48:24.000000000 +0900
+++ common/UCvsConsole.cpp	2012-11-06 16:16:19.000000000 +0900
@@ -22,6 +22,7 @@
  * 
  */
 
+#include <cstdlib>
 #include "stdafx.h"
 
 #if qGTK
@@ -230,7 +231,7 @@
 			nEndChar = w.selection_end_pos;
 		}
 		
-		guint long length = nEndChar - nStartChar;
+		gulong length = nEndChar - nStartChar;
 		if(length > 0 && nStartChar < len)
 		{			
 			char *buf = (char *)malloc((length + 1) * sizeof(char));
