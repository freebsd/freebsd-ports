--- lib/libimhex/include/hex/api/content_registry.hpp.orig	2023-05-21 12:30:36 UTC
+++ lib/libimhex/include/hex/api/content_registry.hpp
@@ -17,6 +17,7 @@
 #include <vector>
 
 #include <nlohmann/json_fwd.hpp>
+#include <jthread.hpp>
 
 using ImGuiDataType = int;
 using ImGuiInputTextFlags = int;
