--- curlpp/Info.cpp.orig	Sun Jan 14 19:53:08 2007
+++ curlpp/Info.cpp	Sun Jan 14 19:53:13 2007
@@ -5,9 +5,11 @@
 #include "Info.hpp"
 
 
+namespace cURLpp {
+
 template< >
 void
-cURLpp::InfoTypeConverter< std::string >::get(cURLpp::Easy &handle, 
+InfoTypeConverter< std::string >::get(cURLpp::Easy &handle, 
 				              CURLINFO info,
 				              std::string &value)
 {
@@ -18,9 +20,11 @@
 
 template< >
 void 
-cURLpp::InfoTypeConverter< std::list< std::string > >::get(cURLpp::Easy &,
+InfoTypeConverter< std::list< std::string > >::get(cURLpp::Easy &,
 			                                   CURLINFO ,
 						           std::list< std::string > &)
 {
   
+}
+
 }
