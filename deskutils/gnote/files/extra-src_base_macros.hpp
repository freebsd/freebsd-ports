Working around c++11 issues with the port compiler used on 9.3.

--- src/base/macros.hpp.orig	2016-01-06 21:33:38.207318000 +0100
+++ src/base/macros.hpp	2016-01-06 21:45:25.932524000 +0100
@@ -29,14 +29,16 @@
 #ifndef __BASE_MACROS_
 #define __BASE_MACROS_
 
-#if __cplusplus < 201103L
+//#if __cplusplus < 201103L
   #include <tr1/memory>
   #include <boost/foreach.hpp>
   #include <boost/lexical_cast.hpp>
+/*
 #else
   #include <memory>
   #include <string>
 #endif
+*/
 
 #if __GNUC__
 #define _PRINTF_FORMAT(f,a) \
@@ -46,7 +48,7 @@
 #endif
 
 // define 'final' and 'override' for pre-C++11 compilers
-#if __cplusplus < 201103L
+//#if __cplusplus < 201103L
   #define final
   #define override
   #define FOREACH(var, container) BOOST_FOREACH(var, container)
@@ -58,6 +60,7 @@
   using std::tr1::enable_shared_from_this;
   using std::tr1::dynamic_pointer_cast;
   using std::tr1::static_pointer_cast;
+/*
 #else
   #define FOREACH(var, container) for(var : container)
   #define TO_STRING(x) std::to_string(x)
@@ -69,5 +72,6 @@
   using std::dynamic_pointer_cast;
   using std::static_pointer_cast;
 #endif
+*/
 
 #endif
