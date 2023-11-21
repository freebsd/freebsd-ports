--- freehdl/kernel-util.hh.orig	2013-04-30 20:24:07.000000000 +0000
+++ freehdl/kernel-util.hh
@@ -24,10 +24,10 @@ using namespace __gnu_cxx;
 // A hash function template used tp generate a hash number from
 // pointer values.
 template<class T>
-class pointer_hash : public hash<unsigned long> {
+class pointer_hash : public __gnu_cxx::hash<unsigned long> {
 public:
   size_t operator()(const T& x) const {
-    return (*(hash<unsigned long> *)this)(((unsigned long)x)>>2);
+    return (*(__gnu_cxx::hash<unsigned long> *)this)(((unsigned long)x)>>2);
   }
 };
 
