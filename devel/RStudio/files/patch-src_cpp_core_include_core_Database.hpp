- Add missing Boost posix_time header for compilation with newer Boost

--- src/cpp/core/include/core/Database.hpp.orig	2025-11-30 07:29:32 UTC
+++ src/cpp/core/include/core/Database.hpp
@@ -23,6 +23,7 @@
 #include <boost/assign.hpp>
 #include <boost/optional.hpp>
 #include <boost/shared_ptr.hpp>
+#include <boost/date_time/posix_time/posix_time.hpp>
 #include <boost/variant.hpp>
 
 #define SOCI_USE_BOOST 1
