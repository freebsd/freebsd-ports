--- CodeLite/cpptoken.h.orig	2014-01-21 10:05:01.000000000 +0100
+++ CodeLite/cpptoken.h	2014-01-21 10:05:10.000000000 +0100
@@ -87,7 +87,7 @@
 	void print();
 
 	// Provide lower-than operator so we can use std::list::sort method
-	bool operator < (const CppToken& rhs) {
+	bool operator < (const CppToken& rhs) const {
 		return filename < rhs.filename;
 	}
 };
