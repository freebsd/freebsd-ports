--- ./kid3/mp3file.cpp.orig	Thu Jan  5 21:15:21 2006
+++ ./kid3/mp3file.cpp	Sat Sep 23 01:28:25 2006
@@ -365,6 +365,11 @@
 		if (!ok || n > 0xff) {
 			n = 0xff;
 		}
+	} else {
+		// ID3v2 genres can be stored as "(9)", "(9)Metal" or "Metal".
+		// If the string does not start with '(', try to get the genre number
+		// from a string containing a genre text.
+		n = Genres::getNumber(str);
 	}
 	return n;
 }
