--- src/sfizz/modulations/ModMatrix.cpp.orig	2024-11-08 05:26:15 UTC
+++ src/sfizz/modulations/ModMatrix.cpp
@@ -13,6 +13,7 @@
 #include "SIMDHelpers.h"
 #include "utility/Debug.h"
 #include <absl/container/flat_hash_map.h>
+#include <absl/strings/str_cat.h>
 #include <absl/strings/string_view.h>
 #include <vector>
 #include <algorithm>
