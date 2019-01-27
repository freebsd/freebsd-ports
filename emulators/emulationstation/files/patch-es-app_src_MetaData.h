Use pugixml from ports, rather than embedded

--- es-app/src/MetaData.h.orig	2018-08-11 01:00:43 UTC
+++ es-app/src/MetaData.h
@@ -4,7 +4,7 @@
 
 #include <boost/date_time/posix_time/ptime.hpp>
 #include <boost/filesystem/path.hpp>
-#include <pugixml/src/pugixml.hpp>
+#include <pugixml.hpp>
 
 enum MetaDataType
 {
