--- sqlite++.h.orig	Wed Aug 18 01:56:28 2004
+++ sqlite++.h	Tue Aug 31 15:40:23 2004
@@ -98,13 +98,11 @@
     SQLQuery &operator<<(int i);
     SQLQuery &operator<<(double i);
     SQLQuery &operator<<(float i) { return *this << double(i); }
-    SQLQuery &operator<<(time_t i) { return *this << (int)i; }
     SQLQuery &operator<<(const string &s);
 
     SQLQuery &operator>>(int &i);
     SQLQuery &operator>>(double &i);
     SQLQuery &operator>>(float &i);
-    SQLQuery &operator>>(time_t &i) { return *this >> ((int&)i); }
     SQLQuery &operator>>(string &s);
 
 private:
