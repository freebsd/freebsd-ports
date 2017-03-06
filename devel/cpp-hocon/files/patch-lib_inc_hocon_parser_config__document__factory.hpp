--- lib/inc/hocon/parser/config_document_factory.hpp.orig	2016-09-23 20:45:10 UTC
+++ lib/inc/hocon/parser/config_document_factory.hpp
@@ -18,11 +18,11 @@ namespace hocon { namespace config_docum
      *       parse options to control how the file is interpreted
      * @return the parsed configuration
      */
-    LIBCPP_HOCON_EXPORT std::shared_ptr<config_document> parse_file(std::string input_file_path,
+    CPP_HOCON_EXPORT std::shared_ptr<config_document> parse_file(std::string input_file_path,
                                                                     config_parse_options options);
 
     /** Parses a file into a config_document instance using default options. */
-    LIBCPP_HOCON_EXPORT std::shared_ptr<config_document> parse_file(std::string input_file_path);
+    CPP_HOCON_EXPORT std::shared_ptr<config_document> parse_file(std::string input_file_path);
 
     /**
      * Parses a string which should be valid HOCON or JSON.
@@ -31,9 +31,9 @@ namespace hocon { namespace config_docum
      * @param options parse options
      * @return the parsed configuration
      */
-    LIBCPP_HOCON_EXPORT std::shared_ptr<config_document> parse_string(std::string s, config_parse_options options);
+    CPP_HOCON_EXPORT std::shared_ptr<config_document> parse_string(std::string s, config_parse_options options);
 
     /** Parses a string into a config_document instance using default options. */
-    LIBCPP_HOCON_EXPORT std::shared_ptr<config_document> parse_string(std::string s);
+    CPP_HOCON_EXPORT std::shared_ptr<config_document> parse_string(std::string s);
 
 }}  // namespace hocon::config_document_factory
