--- src/gui/AboutDialog.cpp.orig	Mon Aug 29 17:14:14 2005
+++ src/gui/AboutDialog.cpp	Mon Aug 29 17:14:51 2005
@@ -106,7 +106,7 @@
 
 	sAuthors += "<ul>";
 	for ( int i = 0; i < authorList.size(); ++i ) {
-		Author a = authorList.at( i );
+		Author a = authorList[i];
 		sAuthors += "<li><p>";
 		sAuthors += "<i>" + a.m_sName + "</i>";
 		sAuthors += "</p></li>";
