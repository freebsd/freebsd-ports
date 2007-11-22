--- rf/ustr.h.orig	2007-11-13 22:31:20.000000000 +0100
+++ rf/ustr.h	2007-11-13 22:32:08.000000000 +0100
@@ -175,13 +175,13 @@
 	//! concatenate
 	UStr & operator<<(int addToStr);
 	//! concatenate
-	UStr & UStr::operator+=(int addToStr);
+	UStr & operator+=(int addToStr);
 	//! concatenate
-	UStr & UStr::operator+=(char *addToStr);
+	UStr & operator+=(char *addToStr);
 	//! concatenate
-	UStr & UStr::operator+=(const char *addToStr);
+	UStr & operator+=(const char *addToStr);
 	//! concatenate
-	UStr & UStr::operator+=(const UStr & addToStr);
+	UStr & operator+=(const UStr & addToStr);
 
 	//! compare
 	inline int compare(const char *thestr) const { return strcmp(*this, thestr); }
