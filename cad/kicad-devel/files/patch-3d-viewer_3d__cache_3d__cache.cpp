After https://github.com/boostorg/uuid/commit/33da3e2a5b87 build fails:

3d-viewer/3d_cache/3d_cache.cpp:37:10: fatal error: 'boost/uuid/sha1.hpp' file not found
#include <boost/uuid/sha1.hpp>
         ^

--- 3d-viewer/3d_cache/3d_cache.cpp.orig	2018-07-03 15:23:16 UTC
+++ 3d-viewer/3d_cache/3d_cache.cpp
@@ -34,7 +34,12 @@
 #include <wx/log.h>
 #include <wx/stdpaths.h>
 
+#include <boost/version.hpp>
+#if (BOOST_VERSION >= 106600)
+#include <boost/uuid/detail/sha1.hpp>
+#else
 #include <boost/uuid/sha1.hpp>
+#endif
 
 #include <glm/glm.hpp>
 #include <glm/ext.hpp>
