--- tools/libime_prediction.cpp.orig	2021-11-05 14:13:24 UTC
+++ tools/libime_prediction.cpp
@@ -8,6 +8,7 @@
 #include "libime/core/datrie.h"
 #include "libime/core/languagemodel.h"
 #include <boost/algorithm/string.hpp>
+#include <array>
 #include <cmath>
 #include <fcitx-utils/log.h>
 #include <fstream>
