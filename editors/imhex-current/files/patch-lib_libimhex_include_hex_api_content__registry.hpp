--- lib/libimhex/include/hex/api/content_registry.hpp.orig	2024-04-13 11:25:28 UTC
+++ lib/libimhex/include/hex/api/content_registry.hpp
@@ -6,6 +6,7 @@
 
 #include <functional>
 #include <map>
+#include <mutex>
 #include <span>
 #include <string>
 #include <utility>
