--- components/files/configurationmanager.hpp.orig	2015-11-24 02:42:35 UTC
+++ components/files/configurationmanager.hpp
@@ -52,11 +52,7 @@ struct ConfigurationManager
         typedef Files::FixedPath<> FixedPathType;
 
         typedef const boost::filesystem::path& (FixedPathType::*path_type_f)() const;
-    #if defined HAVE_UNORDERED_MAP
         typedef std::unordered_map<std::string, path_type_f> TokensMappingContainer;
-    #else
-        typedef std::tr1::unordered_map<std::string, path_type_f> TokensMappingContainer;
-    #endif
 
         void loadConfig(const boost::filesystem::path& path,
             boost::program_options::variables_map& variables,
