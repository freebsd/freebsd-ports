--- include/Savitar/Namespace.h.orig	2023-09-08 18:09:36 UTC
+++ include/Savitar/Namespace.h
@@ -10,6 +10,8 @@
 
 #include <pugixml.hpp>
 
+#include "SavitarExport.h"
+
 namespace xml_namespace
 {
 using xmlns_map_t = std::map<std::string, std::set<std::string>>;
@@ -17,8 +19,8 @@ using xmlns_map_t = std::map<std::string, std::set<std
 [[nodiscard]] std::string getCuraUri();
 [[nodiscard]] std::string getDefaultUri();
 
-[[nodiscard]] xmlns_map_t getAncestralNamespaces(const pugi::xml_node& xml_node);
-[[nodiscard]] std::set<std::string> getNamesFor(const xmlns_map_t& map, const std::string& uri);
+[[nodiscard]] xmlns_map_t SAVITAR_EXPORT getAncestralNamespaces(const pugi::xml_node& xml_node);
+[[nodiscard]] std::set<std::string> SAVITAR_EXPORT getNamesFor(const xmlns_map_t& map, const std::string& uri);
 } // namespace xml_namespace
 
-#endif
\ No newline at end of file
+#endif
