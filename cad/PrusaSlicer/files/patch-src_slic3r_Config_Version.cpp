--- src/slic3r/Config/Version.cpp.orig	2024-04-05 09:25:31 UTC
+++ src/slic3r/Config/Version.cpp
@@ -7,6 +7,7 @@
 #include <cctype>
 
 #include <boost/filesystem/operations.hpp>
+#include <boost/filesystem/directory.hpp>
 #include <boost/nowide/fstream.hpp>
 
 #include "libslic3r/libslic3r.h"
