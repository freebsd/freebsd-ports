--- src/vector.hpp.orig	Fri Aug 15 19:07:16 2003
+++ src/vector.hpp	Wed Nov  5 20:34:27 2003
@@ -107,25 +107,17 @@
 }
 
 template <typename T>
-inline bool operator !=(Vector<T> lhs, Vector<T> rhs)
-{
-  return !(lhs == rhs);
-}
-
-template <typename T>
 inline bool operator ==(Vector<T> lhs, Vector<T> rhs)
 {
   return lhs.x == rhs.x && lhs.y == rhs.y;
 }  
 
-template <>
-inline bool operator ==<double>(Vector<double> lhs, Vector<double> rhs)
+inline bool operator ==(Vector<double> lhs, Vector<double> rhs)
 {
   return std::abs(lhs.x - rhs.x) < 0.001 && std::abs(lhs.y - rhs.y) < 0.001;
 }  
 
-template <>
-inline bool operator ==<float>(Vector<float> lhs, Vector<float> rhs)
+inline bool operator ==(Vector<float> lhs, Vector<float> rhs)
 {
   return std::abs(lhs.x - rhs.x) < 0.001 && std::abs(lhs.y - rhs.y) < 0.001;
 }  
