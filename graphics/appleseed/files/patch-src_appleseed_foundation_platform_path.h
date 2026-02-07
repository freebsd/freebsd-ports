--- src/appleseed/foundation/platform/path.h.orig	2019-08-31 15:49:01 UTC
+++ src/appleseed/foundation/platform/path.h
@@ -40,6 +40,7 @@
 #include "main/dllsymbol.h"
 
 // Boost headers.
+#include "boost/filesystem/exception.hpp"
 #include "boost/filesystem/operations.hpp"
 #include "boost/filesystem/path.hpp"
 
