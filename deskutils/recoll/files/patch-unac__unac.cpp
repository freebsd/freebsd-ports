--- ./unac/unac.cpp.orig	2013-09-30 18:45:06.000000000 +0200
+++ ./unac/unac.cpp	2013-10-29 15:57:51.000000000 +0100
@@ -31,9 +31,9 @@
 #include <map>
 #include <string>
 #include <algorithm>
-#include <tr1/unordered_map>
+#include "unordered_defs.h"
 using std::string;
-using std::tr1::unordered_map;
+
 #include "smallut.h"
 
 /* 
@@ -42,10 +42,10 @@
    instead according to some local rule. There will usually be very
    few of them, but they must be looked up for every translated char.
  */
-unordered_map<unsigned short, string> except_trans;
+STD_UNORDERED_MAP<unsigned short, string> except_trans;
 static inline bool is_except_char(unsigned short c, string& trans)
 {
-    unordered_map<unsigned short, string>::const_iterator it 
+    STD_UNORDERED_MAP<unsigned short, string>::const_iterator it 
 	= except_trans.find(c);
     if (it == except_trans.end())
 	return false;
