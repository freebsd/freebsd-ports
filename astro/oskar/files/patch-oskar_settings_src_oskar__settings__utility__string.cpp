--- oskar/settings/src/oskar_settings_utility_string.cpp.orig	2018-07-23 04:34:42 UTC
+++ oskar/settings/src/oskar_settings_utility_string.cpp
@@ -39,6 +39,7 @@
 #include <cmath>
 #include <cstdarg>
 #include <string>
+#include "fcvt.h"
 
 std::string oskar_settings_utility_string_reduce(const std::string& str,
                                                  const std::string& fill,
