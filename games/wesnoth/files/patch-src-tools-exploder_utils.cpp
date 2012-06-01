--- src/tools/exploder_utils.cpp.orig	2012-05-09 12:03:45.000000000 +0200
+++ src/tools/exploder_utils.cpp	2012-05-09 12:04:21.000000000 +0200
@@ -16,6 +16,7 @@
 #include "game_config.hpp"
 #include "serialization/string_utils.hpp"
 #include <png.h>
+#include <zlib.h>
 
 exploder_point::exploder_point(const std::string &s)
 	: x(0)
