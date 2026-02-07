--- src/appleseed/foundation/utility/benchmark/benchmarkaggregator.cpp.orig	2019-08-31 15:49:01 UTC
+++ src/appleseed/foundation/utility/benchmark/benchmarkaggregator.cpp
@@ -40,6 +40,7 @@
 
 // Boost headers.
 #include "boost/date_time/posix_time/posix_time.hpp"
+#include "boost/filesystem/directory.hpp"
 #include "boost/filesystem/operations.hpp"
 #include "boost/filesystem/path.hpp"
 #include "boost/regex.hpp"
