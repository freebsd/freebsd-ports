- Add missing Boost posix_time header for compilation with newer Boost

--- src/cpp/core/include/core/Timer.hpp.orig	2025-11-30 07:29:32 UTC
+++ src/cpp/core/include/core/Timer.hpp
@@ -19,6 +19,7 @@
 #include <functional>
 #include <boost/asio/io_context.hpp>
 #include <boost/asio/deadline_timer.hpp>
+#include <boost/date_time/posix_time/posix_time.hpp>
 
 namespace rstudio {
 namespace core {
