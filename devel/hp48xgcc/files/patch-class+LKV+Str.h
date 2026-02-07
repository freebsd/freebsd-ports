--- class/LKV/Str.h	3 Nov 2004 06:57:51 -0000	1.1
+++ class/LKV/Str.h	20 Feb 2006 11:18:51 -0000
@@ -68,6 +68,15 @@ public:
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
@@ -78,11 +87,11 @@ public:
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
 	
@@ -168,11 +177,11 @@ Str NtoHex(unsigned long val, unsigned s
 Str FtoStr(double val);
 Str LtoStr(long);
 
-class ostream;
-ostream & operator<< (ostream & o, const Str & s);
+#include <iostream>
+
+std::ostream & operator<< (std::ostream & o, const Str & s);
 
-class istream;
-istream & operator>> (istream & i, Str & s);
+std::istream & operator>> (std::istream & i, Str & s);
 
 class BOstream;
 BOstream & operator<< (BOstream & o, const Str & s);
@@ -180,4 +189,4 @@ BOstream & operator<< (BOstream & o, con
 class BIstream;
 BIstream & operator>> (BIstream & i, Str & s);
 
-#endif Str_h
+#endif /* Str_h */
