--- krss/schemeparser.cpp.orig	Mon Nov 26 10:12:50 2001
+++ krss/schemeparser.cpp	Wed May 21 10:32:25 2003
@@ -18,6 +18,8 @@
 #include "schemeparser.h"
 #include <iostream>
 
+using namespace std;
+
 SchemeParser::SchemeParser()
 {
 	schemetag = QString("scheme");
@@ -341,9 +343,6 @@
 					font.setUnderline(true);
 				else
 					font.setUnderline(false);
-			}
-			else if(atts.qName(i).compare("charset") == 0) {
-				font.setCharSet((QFont::CharSet) atts.value(i).toInt());
 			}
 		}
 		if(mReadingChannel) {
