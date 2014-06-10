--- levelmap.cpp.orig	2007-11-06 00:03:04.000000000 +0100
+++ levelmap.cpp	2007-11-06 00:07:30.000000000 +0100
@@ -199,7 +199,7 @@
 };
 
 // Possible text tokens in the map text
-char *tokenStrings[] = {
+const char *tokenStrings[] = {
 	"notoken",
 	"{",
 	"}",
@@ -1225,7 +1225,7 @@
 #endif
 		for( int i = 0; i < NUM_EXTERNAL_TOKENS; i ++ )
 		{
-			tokenMap[tokenStrings[i]] = i;
+			tokenMap[(char *)tokenStrings[i]] = i;
 		}
 	}
 
