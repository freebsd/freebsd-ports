--- src/include/xm_hashmap.h.orig	2011-10-12 00:18:17.000000000 +0400
+++ src/include/xm_hashmap.h	2013-09-13 22:30:46.334969348 +0400
@@ -14,7 +14,7 @@
 namespace HashNamespace=std;
 #endif
 struct hashcmp_str {
-  bool operator()(const char* s1, const char* s2) {
+  bool operator()(const char* s1, const char* s2) const {
     if(s1 == NULL || s2 == NULL) {
       return false;
     }
