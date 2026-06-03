Remove deprecated std::binary_function base class.

C++17 removed std::binary_function which was deprecated in C++11.
Replace with plain structs that define operator().

--- common/clitkCommon.txx.orig	2025-04-17 12:54:38 UTC
+++ common/clitkCommon.txx
@@ -135,7 +135,7 @@ template<class Type>
 
 //--------------------------------------------------------------------
 template<class Type>
-struct vectorComparisonLowerThan: public std::binary_function<int, int, bool> {
+struct vectorComparisonLowerThan {
   vectorComparisonLowerThan(const std::vector<Type> & v):vect(v) {};
   bool operator()(int x, int y) {
     return (vect[x] < vect[y]);
@@ -146,7 +146,7 @@ template<class Type>
 
 //--------------------------------------------------------------------
 template<class Type>
-struct vectorComparisonGreaterThan: public std::binary_function<int, int, bool> {
+struct vectorComparisonGreaterThan {
   vectorComparisonGreaterThan(const std::vector<Type> & v):vect(v) {};
   bool operator()(int x, int y) {
     return (vect[x] > vect[y]);
