Use pugixml from ports, rather than embedded

--- es-core/src/ThemeData.h.orig	2018-08-11 01:03:37 UTC
+++ es-core/src/ThemeData.h
@@ -6,7 +6,7 @@
 #include <boost/filesystem/path.hpp>
 #include <boost/variant/get.hpp>
 #include <boost/variant/variant.hpp>
-#include <pugixml/src/pugixml.hpp>
+#include <pugixml.hpp>
 #include <deque>
 #include <map>
 #include <sstream>
