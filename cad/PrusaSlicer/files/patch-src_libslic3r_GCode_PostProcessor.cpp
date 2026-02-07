--- src/libslic3r/GCode/PostProcessor.cpp.orig	2025-04-10 11:26:51 UTC
+++ src/libslic3r/GCode/PostProcessor.cpp
@@ -152,7 +152,14 @@ static int run_script(const std::string &script, const
 
 #include <cstdlib>   // getenv()
 #include <sstream>
+#if BOOST_VERSION >= 108800 // v2 is now default
+#define BOOST_PROCESS_VERSION 1
+#include <boost/process/v1/child.hpp>
+#include <boost/process/v1/io.hpp>
+#include <boost/process/v1/pipe.hpp>
+#else
 #include <boost/process.hpp>
+#endif
 
 namespace process = boost::process;
 
