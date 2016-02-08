--- src/colormap.h.orig	2015-03-05 16:25:10 UTC
+++ src/colormap.h
@@ -5,9 +5,11 @@
 #include <list>
 #include "linalg.h"
 
+#ifndef Q_MOC_RUN
 #include <boost/shared_ptr.hpp>
 #include <boost/filesystem.hpp>
 #include <boost/property_tree/ptree.hpp>
+#endif
 
 namespace fs = boost::filesystem;
 
