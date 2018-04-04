https://bazaar.launchpad.net/~widelands-dev/widelands/trunk/revision/8641

--- src/graphic/text/bidi.h.orig	2016-11-10 07:28:01 UTC
+++ src/graphic/text/bidi.h
@@ -40,7 +40,7 @@ bool has_rtl_character(std::vector<std::string> input)
 // True if a string contains a character from the script's code blocks
 bool has_script_character(const char* input, UI::FontSets::Selector script);
 UI::FontSet const* find_fontset(const char* word, const UI::FontSets& fontsets);
-std::string icustring2string(const UnicodeString& convertme);
+std::string icustring2string(const icu::UnicodeString& convertme);
 std::string icuchar2string(const UChar& convertme);
 bool cannot_start_line(const UChar& c);
 bool cannot_end_line(const UChar& c);
