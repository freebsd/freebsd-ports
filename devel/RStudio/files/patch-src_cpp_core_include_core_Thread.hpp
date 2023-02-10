- workaround for https://github.com/rstudio/rstudio/issues/12611

--- src/cpp/core/include/core/Thread.hpp.orig	2023-01-22 20:42:46 UTC
+++ src/cpp/core/include/core/Thread.hpp
@@ -17,6 +17,7 @@
 #define CORE_THREAD_HPP
 
 #include <queue>
+#include <set>
 
 #include <boost/utility.hpp>
 #include <boost/function.hpp>
