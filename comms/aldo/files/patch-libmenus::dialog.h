--- libmenus/dialog.h.orig	Fri Oct  3 00:23:55 2003
+++ libmenus/dialog.h	Fri Sep 17 18:44:10 2004
@@ -24,6 +24,7 @@
  *                                                                         *
  ***************************************************************************/
 
+#include <iostream>
 #include <string>
 #include <vector>
 
@@ -121,7 +122,7 @@
     unsigned int choice = 0;
     do
     {
-	std::cout<<endl<<m_prompt;
+	std::cout<<std::endl<<m_prompt;
 
 	std::string trash;
 	std::cin>>trash;
