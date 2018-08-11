--- plugin/x/src/xpl_regex.cc.orig	2018-08-11 18:13:47 UTC
+++ plugin/x/src/xpl_regex.cc
@@ -53,7 +53,7 @@ bool xpl::Regex::match(const char *value
    * and parse the text patter each time that xpl::Regex::match
    * is called.
    */
-  UnicodeString value_as_utf8{icu::UnicodeString::fromUTF8(value)};
+  icu::UnicodeString value_as_utf8{icu::UnicodeString::fromUTF8(value)};
   std::unique_ptr<icu::RegexMatcher> regexp{
       m_pattern->matcher(value_as_utf8, match_status)};
 
