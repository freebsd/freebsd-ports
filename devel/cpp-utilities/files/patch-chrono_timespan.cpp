- workaround for https://github.com/Martchus/cpp-utilities/issues/29

--- chrono/timespan.cpp.orig	2023-12-07 06:36:21 UTC
+++ chrono/timespan.cpp
@@ -5,6 +5,7 @@
 #include "../conversion/stringbuilder.h"
 #include "../conversion/stringconversion.h"
 
+#include <array>
 #include <charconv>
 #include <cmath>
 #include <cstdlib>
