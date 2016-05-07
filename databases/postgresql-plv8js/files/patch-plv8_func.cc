--- plv8_func.cc.orig	2015-05-26 19:46:56.000000000 +0200
+++ plv8_func.cc	2016-04-04 17:11:11.341047000 +0200
@@ -10,11 +10,6 @@
 #include <sstream>
 
 extern "C" {
-#define delete		delete_
-#define namespace	namespace_
-#define	typeid		typeid_
-#define	typename	typename_
-#define	using		using_
 
 #include "access/xact.h"
 #include "catalog/pg_type.h"
@@ -23,11 +18,6 @@ extern "C" {
 #include "utils/builtins.h"
 #include "utils/lsyscache.h"
 
-#undef delete
-#undef namespace
-#undef typeid
-#undef typename
-#undef using
 } // extern "C"
 
 using namespace v8;
