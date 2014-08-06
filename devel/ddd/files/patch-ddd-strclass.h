--- ddd/strclass.h.orig	2009-02-11 17:25:06 +0000
+++ ddd/strclass.h
@@ -811,9 +811,9 @@
 		     const regex& sep);
 
     friend string common_prefix(const string& x, const string& y, 
-				int startpos = 0);
+				int startpos);
     friend string common_suffix(const string& x, const string& y, 
-				int startpos = -1);
+				int startpos);
     friend string replicate(char c, int n);
     friend string replicate(const string& y, int n);
     friend string join(const string *src, int n, const string& sep);
@@ -864,8 +864,8 @@
     friend std::istream& operator>>(std::istream& s, string& x);
 
     friend int readline(std::istream& s, string& x, 
-			char terminator = '\n',
-			int discard_terminator = 1);
+			char terminator,
+			int discard_terminator);
 
     // Status
     unsigned int length() const;
@@ -892,6 +892,15 @@
 typedef string strTmp; // for backward compatibility
 #endif
 
+string common_prefix(const string& x, const string& y, 
+				int startpos = 0);
+string common_suffix(const string& x, const string& y, 
+				int startpos = -1);
+
+int readline(std::istream& s, string& x, 
+	char terminator = '\n',
+	int discard_terminator = 1);
+
 // Other externs
 
 int compare(const string& x,    const string& y);
