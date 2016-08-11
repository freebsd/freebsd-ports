--- plv8_type.cc.orig	2015-05-26 19:46:56.000000000 +0200
+++ plv8_type.cc	2016-04-04 17:11:11.341361000 +0200
@@ -8,11 +8,6 @@
 #include "plv8.h"
 
 extern "C" {
-#define delete		delete_
-#define namespace	namespace_
-#define	typeid		typeid_
-#define	typename	typename_
-#define	using		using_
 
 #if PG_VERSION_NUM >= 90300
 #include "access/htup_details.h"
@@ -29,11 +24,6 @@ extern "C" {
 #include "utils/syscache.h"
 #include "utils/typcache.h"
 
-#undef delete
-#undef namespace
-#undef typeid
-#undef typename
-#undef using
 } // extern "C"
 
 //#define CHECK_INTEGER_OVERFLOW
