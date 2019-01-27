Use pugixml from ports, rather than embedded

--- es-core/src/Settings.cpp.orig	2018-08-11 01:05:37 UTC
+++ es-core/src/Settings.cpp
@@ -3,7 +3,7 @@
 #include "Log.h"
 #include "platform.h"
 #include <boost/filesystem/operations.hpp>
-#include <pugixml/src/pugixml.hpp>
+#include <pugixml.hpp>
 
 Settings* Settings::sInstance = NULL;
 
