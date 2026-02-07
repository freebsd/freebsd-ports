- Add missing Boost posix_time header for compilation with newer Boost

--- src/cpp/core/include/core/PeriodicCommand.hpp.orig	2025-11-30 07:29:32 UTC
+++ src/cpp/core/include/core/PeriodicCommand.hpp
@@ -17,6 +17,7 @@
 #ifndef CORE_PERIODIC_COMMAND_HPP
 #define CORE_PERIODIC_COMMAND_HPP
 
+#include <boost/date_time/posix_time/posix_time.hpp>
 #include <core/ScheduledCommand.hpp>
 
 namespace rstudio {
