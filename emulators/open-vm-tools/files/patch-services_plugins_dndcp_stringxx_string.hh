--- services/plugins/dndcp/stringxx/string.hh.orig	2024-11-05 17:51:28 UTC
+++ services/plugins/dndcp/stringxx/string.hh
@@ -87,7 +87,7 @@ typedef std::string utf8string;
  * to replace the std::string in our codebase.
  */
 typedef std::string utf8string;
-typedef std::basic_string<utf16_t> utf16string;
+typedef std::u16string utf16string;
 
 class VMSTRING_EXPORT string
 {
