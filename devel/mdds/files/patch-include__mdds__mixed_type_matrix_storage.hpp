--- include/mdds/mixed_type_matrix_storage.hpp.orig	2012-07-18 23:09:49.000000000 -0400
+++ include/mdds/mixed_type_matrix_storage.hpp	2012-08-09 14:14:09.000000000 -0400
@@ -32,6 +32,10 @@
 
 #include <boost/ptr_container/ptr_vector.hpp>
 #include <boost/ptr_container/ptr_map.hpp>
+// Boost.Pool indirectly pulls in Boost.System, causing linking error
+// with Boost 1.50, because some (deprecated) symbols from System are
+// not found.
+#define BOOST_SYSTEM_NO_DEPRECATED
 #include <boost/pool/object_pool.hpp>
 
 namespace mdds {
