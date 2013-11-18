--- isql++/isql++.h.orig	2013-11-18 21:03:56.000000000 +0700
+++ isql++/isql++.h	2013-11-18 21:04:06.000000000 +0700
@@ -115,7 +115,7 @@
   string buffer_;
 
   struct ltcasestr {
-    bool operator()(const string& s1, const string& s2) {
+    bool operator()(const string& s1, const string& s2) const {
       return strcasecmp(s1.c_str(),s2.c_str())<0;
     }
   };
