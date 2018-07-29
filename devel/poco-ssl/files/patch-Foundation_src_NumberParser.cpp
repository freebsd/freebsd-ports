src/NumberParser.cpp:127:35: error: invalid suffix on literal; C++11 requires a space between literal and identifier [-Wreserved-user-defined-literal]
        return std::sscanf(s.c_str(), "%"I64_FMT"d%c", &value, &temp) == 1;
                                                 ^

--- Foundation/src/NumberParser.cpp.orig	2018-07-29 11:21:10 UTC
+++ Foundation/src/NumberParser.cpp
@@ -124,7 +124,7 @@ Int64 NumberParser::parse64(const std::string& s)
 bool NumberParser::tryParse64(const std::string& s, Int64& value)
 {
 	char temp;
-	return std::sscanf(s.c_str(), "%"I64_FMT"d%c", &value, &temp) == 1;
+	return std::sscanf(s.c_str(), "%" I64_FMT "d%c", &value, &temp) == 1;
 }
 
 
@@ -141,7 +141,7 @@ UInt64 NumberParser::parseUnsigned64(const std::string
 bool NumberParser::tryParseUnsigned64(const std::string& s, UInt64& value)
 {
 	char temp;
-	return std::sscanf(s.c_str(), "%"I64_FMT"u%c", &value, &temp) == 1;
+	return std::sscanf(s.c_str(), "%" I64_FMT "u%c", &value, &temp) == 1;
 }
 
 
@@ -158,7 +158,7 @@ UInt64 NumberParser::parseHex64(const std::string& s)
 bool NumberParser::tryParseHex64(const std::string& s, UInt64& value)
 {
 	char temp;
-	return std::sscanf(s.c_str(), "%"I64_FMT"x%c", &value, &temp) == 1;
+	return std::sscanf(s.c_str(), "%" I64_FMT "x%c", &value, &temp) == 1;
 }
 
 
