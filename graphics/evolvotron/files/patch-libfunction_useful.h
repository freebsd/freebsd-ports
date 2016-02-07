--- libfunction/useful.h.orig	2013-01-26 12:49:04 UTC
+++ libfunction/useful.h
@@ -40,6 +40,7 @@
 #include <sstream>
 #include <vector>
 
+#ifndef Q_MOC_RUN
 #include <boost/array.hpp>
 #include <boost/ptr_container/ptr_map.hpp>
 #include <boost/ptr_container/ptr_vector.hpp>
@@ -49,6 +50,7 @@
 #include <boost/tuple/tuple.hpp>
 #include <boost/utility.hpp>
 #include <boost/version.hpp>
+#endif
 
 //! Convenience typedef.
 typedef unsigned int uint;
