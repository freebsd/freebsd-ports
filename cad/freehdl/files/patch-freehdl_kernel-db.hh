--- freehdl/kernel-db.hh.orig	2013-04-30 20:25:10.000000000 +0000
+++ freehdl/kernel-db.hh
@@ -254,10 +254,10 @@ public:
 
 // A hash function template used tp generate a hash number from
 // d
-class db_basic_key_hash : public hash<unsigned long> {
+class db_basic_key_hash : public __gnu_cxx::hash<unsigned long> {
 public:
   size_t operator()(const db_basic_key& x) const {
-    return (*(hash<unsigned long> *)this)(((unsigned long)x.value)>>2);
+    return (*(__gnu_cxx::hash<unsigned long> *)this)(((unsigned long)x.value)>>2);
   }
 };
 
