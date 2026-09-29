--- libs/mpi/src/python/request_with_value.hpp.orig	2026-08-05 17:09:12 UTC
+++ libs/mpi/src/python/request_with_value.hpp
@@ -65,7 +65,12 @@ namespace boost { namespace mpi { namespace python {
       friend request_with_value communicator_irecv_content(
           const communicator&, int, int, content&);
   };
-
+      
+  // FIXME: requests are not comparable, thus this operator makes no sense.
+  // Unfortunately, indexing_suites insist on having __contains__ available.
+  // Just make it error out for now.
+  bool
+  operator==(request_with_value const& ,request_with_value const&);
 } } }
 
 #endif
