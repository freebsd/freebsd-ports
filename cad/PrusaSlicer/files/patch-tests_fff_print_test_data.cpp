commit 926ae0471800abd1e5335e251a5934570eb8f6ff
Author: Vojtech Bubnik <bubnikv@gmail.com>
Date:   2022-04-25 11:32:03 +0200

    Follow-up to 408e56f0390f20aaf793e0aa0c70c4d9544401d4
    Fixing compilation of tests on latest GCC/boost

diff --git tests/fff_print/test_data.cpp tests/fff_print/test_data.cpp
index 32e31c264..f7077007d 100644
--- tests/fff_print/test_data.cpp
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
