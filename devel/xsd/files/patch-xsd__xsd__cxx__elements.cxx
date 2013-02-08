C++11 build fix: literals are supposed to be separated with a space.
--- xsd/xsd/cxx/elements.cxx~	2012-08-10 22:50:51.000000000 -0300
+++ xsd/xsd/cxx/elements.cxx	2012-08-10 22:51:52.000000000 -0300
@@ -209,7 +209,7 @@
     // Default mapping.
     //
     nsr_mapping_.push_back (
-      Regex (L"#^.* (.*?/)??"L"(([a-zA-Z_]\\w*)(/[a-zA-Z_]\\w*)*)/?$#$2#"));
+      Regex (L"#^.* (.*?/)??" L"(([a-zA-Z_]\\w*)(/[a-zA-Z_]\\w*)*)/?$#$2#"));
     nsr_mapping_.push_back (
       Regex (L"#^.* http://www\\.w3\\.org/2001/XMLSchema$#xml_schema#"));
 
