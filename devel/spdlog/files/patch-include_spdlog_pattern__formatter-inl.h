--- include/spdlog/pattern_formatter-inl.h.orig	2020-05-17 07:10:09 UTC
+++ include/spdlog/pattern_formatter-inl.h
@@ -14,6 +14,7 @@
 #include <spdlog/formatter.h>
 
 #include <array>
+#include <cassert>
 #include <chrono>
 #include <ctime>
 #include <cctype>
