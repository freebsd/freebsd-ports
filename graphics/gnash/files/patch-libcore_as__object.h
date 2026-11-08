--- libcore/as_object.h.orig	2019-01-30 23:45:03 UTC
+++ libcore/as_object.h
@@ -28,6 +28,7 @@
 #include <cmath>
 #include <utility> 
 #include <memory>
+#include <list>
 #include <boost/noncopyable.hpp>
 
 #include "GC.h" // for inheritance from GcResource (to complete)
