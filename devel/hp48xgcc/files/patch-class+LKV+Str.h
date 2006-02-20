--- class/LKV/Str.h	3 Nov 2004 06:57:51 -0000	1.1
+++ class/LKV/Str.h	20 Feb 2006 11:18:51 -0000
@@ -68,6 +68,15 @@
 		return !(operator>(rv));
 	};
 	
+	int operator<(const char * p) const;
+	inline int operator>=(const char * p) const {
+		return !(operator<(p));
+	};
+//	int operator>(const char * p) const;
+//	inline int operator<=(const char * p) const {
+//		return !(operator>(p));
+//	};
+
 	// ====== casting ======
 	
 	inline operator const char *() const {
@@ -78,11 +87,11 @@
 		return (const unsigned char *) adr;
 	}
 
-	inline operator char *() {
+	inline operator char *() const {
 		return adr;
 	}
 	
-	inline operator unsigned char *() {
+	inline operator unsigned char *() const {
 		return (unsigned char *) adr;
 	}
 	
@@ -168,6 +177,8 @@
 Str FtoStr(double val);
 Str LtoStr(long);
 
+#include <iostream.h>
+
 class ostream;
 ostream & operator<< (ostream & o, const Str & s);
 
@@ -180,4 +191,4 @@
 class BIstream;
 BIstream & operator>> (BIstream & i, Str & s);
 
-#endif Str_h
+#endif /* Str_h */
