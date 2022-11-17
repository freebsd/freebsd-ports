--- tests/fff_print/test_data.cpp.orig	2022-09-06 07:09:19 UTC
+++ tests/fff_print/test_data.cpp
@@ -11,6 +11,7 @@
 #include <string>
 
 #include <boost/nowide/cstdio.hpp>
+#include <boost/nowide/fstream.hpp>
 #include <boost/filesystem.hpp>
 #include <libslic3r/ModelArrange.hpp>
 
@@ -286,7 +287,7 @@ std::string gcode(Print & print)
     print.set_status_silent();
     print.process();
     print.export_gcode(temp.string(), nullptr, nullptr);
-    std::ifstream t(temp.string());
+    boost::nowide::ifstream t(temp.string());
 	std::string str((std::istreambuf_iterator<char>(t)), std::istreambuf_iterator<char>());
 	boost::nowide::remove(temp.string().c_str());
 	return str;
