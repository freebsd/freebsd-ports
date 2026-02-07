- Add missing Boost posix_time header for compilation with newer Boost

--- src/cpp/core/include/core/IncrementalCommand.hpp.orig	2025-11-30 07:29:32 UTC
+++ src/cpp/core/include/core/IncrementalCommand.hpp
@@ -18,6 +18,7 @@
 #define CORE_INCREMENTAL_COMMAND_HPP
 
 
+#include <boost/date_time/posix_time/posix_time.hpp>
 #include <core/ScheduledCommand.hpp>
 
 namespace rstudio {
