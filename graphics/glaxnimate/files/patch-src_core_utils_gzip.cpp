- workaround for https://gitlab.com/mattbas/glaxnimate/-/issues/486

--- src/core/utils/gzip.cpp.orig	2022-02-08 22:18:22 UTC
+++ src/core/utils/gzip.cpp
@@ -1,5 +1,6 @@
 #include "gzip.hpp"
 
+#include <array>
 #include <cstring>
 
 #include <QFile>
