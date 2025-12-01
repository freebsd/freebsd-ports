- Add missing Boost posix_time header for compilation with newer Boost

--- src/cpp/core/include/core/Thread.hpp.orig	2025-11-30 07:29:32 UTC
+++ src/cpp/core/include/core/Thread.hpp
@@ -23,6 +23,7 @@
 
 #include <boost/utility.hpp>
 #include <boost/function.hpp>
+#include <boost/date_time/posix_time/posix_time.hpp>
 
 #include <shared_core/Error.hpp>
 
