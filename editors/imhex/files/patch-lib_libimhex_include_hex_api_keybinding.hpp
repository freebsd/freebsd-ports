--- lib/libimhex/include/hex/api/keybinding.hpp.orig	2022-01-16 14:56:46 UTC
+++ lib/libimhex/include/hex/api/keybinding.hpp
@@ -7,6 +7,8 @@
 #include <map>
 #include <set>
 
+#include <range/v3/compare.hpp>
+
 struct ImGuiWindow;
 
 namespace hex {
