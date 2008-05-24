--- src/python/universe_util_export.cpp.orig	2008-04-24 16:11:53.000000000 +0400
+++ src/python/universe_util_export.cpp	2008-05-05 23:56:04.000000000 +0400
@@ -3,17 +3,18 @@
 /* ToDo: Fix so Boost 1.28 is supported */
 #if BOOST_VERSION != 102800
 
-#include "cmd/container.h"
-#include <string>
-#include "init.h"
-#include "gfx/vec.h"
-#include "cmd/unit_generic.h"
 #include "python_class.h"
 #if BOOST_VERSION != 102800
 #include <boost/python.hpp>
 #else
 #include <boost/python/objects.hpp>
 #endif
+
+#include "cmd/container.h"
+#include <string>
+#include "init.h"
+#include "gfx/vec.h"
+#include "cmd/unit_generic.h"
 #include "universe_util.h"
 #include "cmd/unit_util.h"
 #include "faction_generic.h"
