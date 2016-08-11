--- plv8.cc.orig	2015-05-26 19:46:56.000000000 +0200
+++ plv8.cc	2016-04-04 17:11:11.340628000 +0200
@@ -9,11 +9,6 @@
 #include <new>
 
 extern "C" {
-#define delete		delete_
-#define namespace	namespace_
-#define	typeid		typeid_
-#define	typename	typename_
-#define	using		using_
 
 #if PG_VERSION_NUM >= 90300
 #include "access/htup_details.h"
@@ -32,12 +27,6 @@ extern "C" {
 #include "utils/rel.h"
 #include "utils/syscache.h"
 
-#undef delete
-#undef namespace
-#undef typeid
-#undef typename
-#undef using
-
 PG_MODULE_MAGIC;
 
 PG_FUNCTION_INFO_V1(plv8_call_handler);
