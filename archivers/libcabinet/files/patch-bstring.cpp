--- bstring.cpp.orig	1999-10-24 11:29:53 UTC
+++ bstring.cpp
@@ -15,7 +15,7 @@
 
 #include "bstring.h"
 #include <string.h>
-#include <fstream.h>
+#include <fstream>
 
 ///////////////////////////////////////***************************************
 
@@ -91,7 +91,7 @@ b_string& b_string::operator += (const c
 
 b_string b_string::operator + (const char* s)
 {
-	b_string temp = str;
+	b_string temp (str);
 	return temp += s;
 }
 
@@ -150,7 +150,7 @@ b_string& b_string::StpCpy(const char* s
 		if(strlen(str) < strlen(s))	// If more memory is needed
 			*this = s;			// Use assign function
 		else						// If stpcpy can be used
-			stpcpy(str, s);		// Copy s into str
+			strcpy(str, s);		// Copy s into str
 	}
 
 	return *this;					// Return a refrence to this object
@@ -217,4 +217,4 @@ istream& operator >> (istream& input, b_
 
 //*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/
 
-#endif
\ No newline at end of file
+#endif
