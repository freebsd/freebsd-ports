--- src/libslic3r/Utils/DirectoriesUtils.cpp.orig	2024-07-03 10:13:37 UTC
+++ src/libslic3r/Utils/DirectoriesUtils.cpp
@@ -3,6 +3,7 @@
 
 #include <boost/filesystem/path.hpp>
 #include <boost/log/trivial.hpp>
+#include <boost/nowide/convert.hpp>
 
 #if defined(_WIN32)
 
@@ -46,7 +47,7 @@ static std::string GetDataDir()
     return  boost::nowide::narrow(buffer);
 }
 
-#elif defined(__linux__)
+#elif (defined(__linux__) || defined(__FreeBSD__))
 
 #include <stdlib.h>
 #include <pwd.h>
