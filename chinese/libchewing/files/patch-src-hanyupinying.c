--- src/hanyupinying.c.orig	Thu Apr 27 06:42:41 2006
+++ src/hanyupinying.c	Thu Apr 27 06:43:31 2006
@@ -26,7 +26,6 @@
 
 static PinYingZuinMap* InitialsMap()
 {
-	HANYU_INITIALS = 26;
 	static PinYingZuinMap map[ 26 ] = {
 		{"b" , "1"}, {"p" , "q"}, {"m" , "a"}, {"f" ,"z"},
 		{"d" , "2"}, {"t" , "w"}, {"n" , "s"}, {"l" ,"x"},
@@ -36,12 +35,12 @@
 		{"shi", "g"}, {"sh", "g"}, {"ri", "b"}, {"r" ,"b"},
 		{"z" , "y"}, {"c" , "h"}, {"s" , "n"}
 	};
+	HANYU_INITIALS = 26;
 	return map;
 }
 
 static PinYingZuinMap* FinalsMap()
 {
-	HANYU_FINALS = 72;
 	static PinYingZuinMap map[ 72 ] = {
 		{"uang","j;"}, {"wang","j;"},
 		{"wong","j/"}, {"weng","j/"},
@@ -92,6 +91,7 @@
 		{"u","j"},
 		{"E",","}
 	};
+	HANYU_FINALS = 72;
 	return map;
 }
 
