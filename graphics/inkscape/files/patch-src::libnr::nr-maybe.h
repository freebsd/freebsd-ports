--- src/libnr/nr-maybe.h.orig	Mon Aug  2 11:58:44 2004
+++ src/libnr/nr-maybe.h	Mon Aug  2 11:59:21 2004
@@ -18,13 +18,14 @@
 
 #include <stdexcept>
 #include <typeinfo>
+#include <string>
 
 namespace NR {
 
 /** An exception class for run-time type errors */
 template <typename T>
 class IsNot : public std::domain_error {
-    IsNot() : domain_error(string("Is not ") + typeid(T).name()) {}
+    IsNot() : domain_error(std::string("Is not ") + typeid(T).name()) {}
 };
 
 /** A type with only one value, which (in principle) is only equal to itself.
