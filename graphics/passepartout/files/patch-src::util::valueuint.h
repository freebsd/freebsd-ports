--- src/util/valueunit.h.orig	Wed Aug 18 23:48:05 2004
+++ src/util/valueunit.h	Thu Aug 19 00:04:04 2004
@@ -15,10 +15,10 @@
   const Value& value() const { return value_; }
   const std::string& unit() const { return unit_; }
   
-private:
+protected:
   Value value_;
   std::string unit_;
-  friend std::istream& operator >> <> (std::istream& in, ValueUnit<Value>& vu);
+  friend std::istream& operator >> (std::istream& in, ValueUnit<Value>& vu);
 };
 
 template <typename Tp>
@@ -44,7 +44,6 @@
  * Special case for float, since readig a float from "14em" barfs, guessing
  * that the 'e' is for an exponent.
  */
-template<>
 std::istream& operator >> (std::istream& in, ValueUnit<float>& vu) {
   in >> std::ws;
   std::string value;
