- workaorund for https://github.com/apache/arrow/issues/45803

--- src/arrow/testing/process.cc.orig	2025-02-11 22:18:18 UTC
+++ src/arrow/testing/process.cc
@@ -33,17 +33,24 @@
 #  include <boost/asio/io_context.hpp>
 
 #  ifdef BOOST_PROCESS_USE_V2
+#undef BOOST_PROCESS_NEED_SOURCE
 #    ifdef BOOST_PROCESS_NEED_SOURCE
 // Workaround for https://github.com/boostorg/process/issues/312
 #      define BOOST_PROCESS_V2_SEPARATE_COMPILATION
 #      ifdef __APPLE__
 #        include <sys/sysctl.h>
 #      endif
-#      include <boost/process/v2.hpp>
-#      include <boost/process/v2/src.hpp>
-#    else
-#      include <boost/process/v2.hpp>
 #    endif
+#    include <boost/process/v2/environment.hpp>
+#    include <boost/process/v2/error.hpp>
+#    include <boost/process/v2/execute.hpp>
+#    include <boost/process/v2/exit_code.hpp>
+#    include <boost/process/v2/pid.hpp>
+#    include <boost/process/v2/popen.hpp>
+#    include <boost/process/v2/process.hpp>
+#    include <boost/process/v2/process_handle.hpp>
+#    include <boost/process/v2/start_dir.hpp>
+#    include <boost/process/v2/stdio.hpp>
 #    include <unordered_map>
 #  else
 // We need BOOST_USE_WINDOWS_H definition with MinGW when we use
