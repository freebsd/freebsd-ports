--- bstring.cpp.orig	2014-07-27 11:17:34.000000000 -0400
+++ bstring.cpp	2014-07-27 11:17:37.000000000 -0400
@@ -15,7 +15,7 @@
 
 #include "bstring.h"
 #include <string.h>
-#include <fstream.h>
+#include <fstream>
 
 ///////////////////////////////////////***************************************
 
@@ -91,7 +91,7 @@
 
 b_string b_string::operator + (const char* s)
 {
-	b_string temp = str;
+	b_string temp (str);
 	return temp += s;
 }
 
@@ -150,7 +150,7 @@
 		if(strlen(str) < strlen(s))	// If more memory is needed
 			*this = s;			// Use assign function
 		else						// If stpcpy can be used
-			stpcpy(str, s);		// Copy s into str
+			strcpy(str, s);		// Copy s into str
 	}
 
 	return *this;					// Return a refrence to this object
@@ -217,4 +217,4 @@
 
 //*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/
 
-#endif
\ No newline at end of file
+#endif
