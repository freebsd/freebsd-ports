--- src/cbang/net/URI.cpp.orig	2026-06-01 04:53:38 UTC
+++ src/cbang/net/URI.cpp
@@ -282,7 +282,7 @@ string URI::encode(const string &s, const char *unesca
   string result;
 
   for (unsigned i = 0; i < s.length(); i++)
-    if (contains(unescaped, s[i])) result.append(1, s[i]);
+    if (::contains(unescaped, s[i])) result.append(1, s[i]);
     else result.append(String::printf("%%%02x", (unsigned)s[i]));
 
   return result;
@@ -331,7 +331,7 @@ void URI::parsePathSegment(const char *&s) {
   string seg;
 
   while (true)
-    if (contains(PATH_SEGMENT_CHARS, *s)) seg.append(1, *s++);
+    if (::contains(PATH_SEGMENT_CHARS, *s)) seg.append(1, *s++);
     else if (*s == '%') seg.append(1, parseEscape(s));
     else break;
 
@@ -343,7 +343,7 @@ void URI::parseScheme(const char *&s) {
   if (!isalpha(*s)) THROW("Expected alpha at start of scheme");
 
   while (true)
-    if (contains(SCHEME_CHARS, *s)) scheme.append(1, *s++);
+    if (::contains(SCHEME_CHARS, *s)) scheme.append(1, *s++);
     else break;
 
   match(s, ':');
@@ -378,7 +378,7 @@ string URI::parseUserPass(const char *&s) {
   string result;
 
   while (true)
-    if (contains(USER_PASS_CHARS, *s)) result.append(1, *s++);
+    if (::contains(USER_PASS_CHARS, *s)) result.append(1, *s++);
     else if (*s == '%') result.append(1, parseEscape(s));
     else break;
 
@@ -394,7 +394,7 @@ void URI::parseHost(const char *&s) {
 
 void URI::parseHost(const char *&s) {
   while (true)
-    if (contains(HOST_CHARS, *s)) host.append(1, *s++);
+    if (::contains(HOST_CHARS, *s)) host.append(1, *s++);
     else break;
 
   if (host.empty()) THROW("Expected host character");
@@ -429,7 +429,7 @@ string URI::parseName(const char *&s) {
   string result;
 
   while (true)
-    if (contains(NAME_CHARS, *s)) result.append(1, *s++);
+    if (::contains(NAME_CHARS, *s)) result.append(1, *s++);
     else if (*s == '%') result.append(1, parseEscape(s));
     else break;
 
@@ -443,7 +443,7 @@ string URI::parseValue(const char *&s) {
   string result;
 
   while (true)
-    if (contains(VALUE_CHARS, *s)) result.append(1, *s++);
+    if (::contains(VALUE_CHARS, *s)) result.append(1, *s++);
     else if (*s == '%') result.append(1, parseEscape(s));
     else break;
 
