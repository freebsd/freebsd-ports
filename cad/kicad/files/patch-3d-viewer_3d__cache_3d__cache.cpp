--- 3d-viewer/3d_cache/3d_cache.cpp.orig	2018-07-13 19:53:52 UTC
+++ 3d-viewer/3d_cache/3d_cache.cpp
@@ -34,7 +34,7 @@
 #include <wx/log.h>
 #include <wx/stdpaths.h>
 
-#include <boost/uuid/sha1.hpp>
+#include <boost/uuid/detail/sha1.hpp>
 
 #include <glm/glm.hpp>
 #include <glm/ext.hpp>
