--- krss/schemeparser.cpp~	Sun Nov 25 17:12:50 2001
+++ krss/schemeparser.cpp	Tue Sep 10 22:58:36 2002
@@ -342,9 +342,6 @@
 				else
 					font.setUnderline(false);
 			}
-			else if(atts.qName(i).compare("charset") == 0) {
-				font.setCharSet((QFont::CharSet) atts.value(i).toInt());
-			}
 		}
 		if(mReadingChannel) {
 			if(mReadingTitle) {
