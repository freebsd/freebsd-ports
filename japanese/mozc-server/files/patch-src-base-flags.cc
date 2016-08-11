--- src/base/flags.cc.orig	2016-03-13 11:22:55.000000000 +0900
+++ src/base/flags.cc	2016-05-24 02:06:01.861439000 +0900
@@ -36,6 +36,9 @@
 #include <sstream>
 #include <string>
 #include <vector>
+#if defined(__GNUC__) && !defined(__clang__) 
+#include <cstdlib>
+#endif
 
 #include "base/port.h"
 #include "base/singleton.h"
@@ -78,6 +81,59 @@
 // function, compiler may warn of "unused function".
 template <typename T> struct StrToNumberImpl;
 
+#if defined(__GNUC__) && !defined(__clang__) 
+static int stoi(const std::string& s) {
+    std::istringstream str(s);
+    int i;
+    str >> i;
+    return i;
+}
+static long stol(const std::string& s) {
+    std::istringstream str(s);
+    long i;
+    str >> i;
+    return i;
+}
+static long long stoll(const std::string& s) {
+    std::istringstream str(s);
+    long long i;
+    str >> i;
+    return i;
+}
+static unsigned long stoul(const std::string& s) {
+    std::istringstream str(s);
+    unsigned long i;
+    str >> i;
+    return i;
+}
+static unsigned long long stoull(const std::string& s) {
+    std::istringstream str(s);
+    unsigned long long i;
+    str >> i;
+    return i;
+}
+template <> struct StrToNumberImpl<int> {
+  static int Do(const string &s) { return stoi(s); }
+};
+
+template <> struct StrToNumberImpl<long> {                  // NOLINT
+  static long Do(const string &s) { return stol(s); }  // NOLINT
+};
+
+template <> struct StrToNumberImpl<long long> {                   // NOLINT
+  static long long Do(const string &s) { return stoll(s); }  // NOLINT
+};
+
+template <> struct StrToNumberImpl<unsigned long> {                   // NOLINT
+  static unsigned long Do(const string &s) { return stoul(s); }  // NOLINT
+};
+
+template <> struct StrToNumberImpl<unsigned long long> {  // NOLINT
+  static unsigned long long Do(const string &s) {         // NOLINT
+    return stoull(s);
+  }
+};
+#else
 template <> struct StrToNumberImpl<int> {
   static int Do(const string &s) { return std::stoi(s); }
 };
@@ -99,6 +155,7 @@
     return std::stoull(s);
   }
 };
+#endif
 
 template <typename T> inline T StrToNumber(const string &s) {
   return StrToNumberImpl<T>::Do(s);
