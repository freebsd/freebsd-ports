--- simgear/nasal/cppbind/NasalHash.hxx.orig	2019-04-23 16:24:11 UTC
+++ simgear/nasal/cppbind/NasalHash.hxx
@@ -23,6 +23,7 @@
 #include "to_nasal.hxx"
 
 #include <simgear/structure/map.hxx>
+#include <boost/core/enable_if.hpp>
 #include <boost/iterator/iterator_facade.hpp>
 
 namespace nasal
