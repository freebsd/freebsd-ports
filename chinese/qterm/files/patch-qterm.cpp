--- qterm.cpp.orig	Thu Oct 25 22:28:43 2001
+++ qterm.cpp	Tue Feb 19 09:37:37 2002
@@ -340,8 +340,8 @@
 			}
 			else if(stat( strGlobal+"/qterm.cfg",&st)== 0)
 			{
-				strCmd="/bin/cp"+strGlobal;
-				strCmd+="qterm.cfg ";
+				strCmd="/bin/cp "+strGlobal;
+				strCmd+="/qterm.cfg ";
 				strCmd+=strMain;
 			 if( system(strCmd)<0 )
 			  {
@@ -382,7 +382,7 @@
 			else if(stat( strGlobal+"/pic",&st)== 0)
 			{
 				strCmd="/bin/cp -fr "+strGlobal;
-				strCmd+="/pic";
+				strCmd+="/pic ";
 				strCmd+=strMain;
 			 if( system(strCmd)<0 )
 			  {
